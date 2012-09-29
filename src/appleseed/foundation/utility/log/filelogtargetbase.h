
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

#ifndef APPLESEED_FOUNDATION_UTILITY_LOG_FILELOGTARGETBASE_H
#define APPLESEED_FOUNDATION_UTILITY_LOG_FILELOGTARGETBASE_H

// appleseed.main headers.
#include "main/dllsymbol.h"

// appleseed.foundation headers.
#include "foundation/utility/log/logmessage.h"
#include "foundation/utility/log/logtargetbase.h"

// Standard headers.
#include <cstdio>

namespace foundation
{

//
// A convenient base class for log targets that write to std::FILE.
//

class DLLSYMBOL FileLogTargetBase
  : public LogTargetBase
{
  protected:
    // Format and display the message.
    void write_message(
        std::FILE*                  file,
        const LogMessage::Category  category,
        const char*                 message) const;
};

}       // namespace foundation

#endif  // !APPLESEED_FOUNDATION_UTILITY_LOG_FILELOGTARGETBASE_H
