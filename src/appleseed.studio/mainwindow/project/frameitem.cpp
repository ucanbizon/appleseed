
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2012 Francois Beaune, Jupiter Jazz Limited
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

// Interface header.
#include "frameitem.h"

// appleseed.studio headers.
#include "mainwindow/project/entityeditorwindow.h"
#include "mainwindow/project/projectbuilder.h"
#include "mainwindow/project/singlemodelentityeditorformfactory.h"
#include "mainwindow/project/tools.h"

// appleseed.renderer headers.
#include "renderer/api/frame.h"

// appleseed.foundation headers.
#include "foundation/utility/uid.h"

// Qt headers.
#include <QString>
#include <QWidget>

// Standard headers.
#include <memory>

using namespace foundation;
using namespace renderer;
using namespace std;

namespace appleseed {
namespace studio {

namespace
{
    const UniqueID g_class_uid = new_guid();
}

FrameItem::FrameItem(
    Frame*          frame,
    ProjectBuilder& project_builder)
  : ItemBase(g_class_uid, frame->get_name())
  , m_frame(frame)
  , m_project_builder(project_builder)
{
    set_allow_deletion(false);
}

void FrameItem::slot_edit()
{
    auto_ptr<EntityEditorWindow::IFormFactory> form_factory(
        new SingleModelEntityEditorFormFactory(
            m_frame->get_name(),
            FrameFactory::get_widget_definitions()));

    open_entity_editor(
        treeWidget(),
        "Edit Frame",
        m_project_builder.get_project(),
        form_factory,
        auto_ptr<EntityEditorWindow::IEntityBrowser>(0),
        m_frame->get_parameters(),
        this,
        SLOT(slot_edit_accepted(foundation::Dictionary)));
}

void FrameItem::slot_edit_accepted(Dictionary values)
{
    catch_entity_creation_errors(&FrameItem::edit, values, "Frame");
}

void FrameItem::edit(const Dictionary& values)
{
    m_frame = m_project_builder.edit_frame(values);

    set_title(QString::fromAscii(m_frame->get_name()));

    qobject_cast<QWidget*>(QObject::sender())->close();
}

}   // namespace studio
}   // namespace appleseed