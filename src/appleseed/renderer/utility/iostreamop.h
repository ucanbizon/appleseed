
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2014 Francois Beaune, The appleseedhq Organization
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

#ifndef APPLESEED_RENDERER_UTILITY_IOSTREAMOP_H
#define APPLESEED_RENDERER_UTILITY_IOSTREAMOP_H

// appleseed.renderer headers.
#include "renderer/utility/trackingspectrum.h"

// appleseed.foundation headers.
#include "foundation/utility/iostreamop.h"

// Standard headers.
#include <cstddef>
#include <iostream>

namespace renderer
{

//
// I/O of appleseed.renderer types from/to C++ streams.
//

// renderer::TrackingSpectrum.
template <typename T, size_t N>
std::ostream& operator<<(std::ostream& s, const TrackingSpectrum<T, N>& spectrum);


//
// iostream operators implementation.
//

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& s, const TrackingSpectrum<T, N>& spectrum)
{
    return foundation::impl::write_sequence(s, spectrum, spectrum.size());
}

}       // namespace renderer

#endif  // !APPLESEED_RENDERER_UTILITY_IOSTREAMOP_H
