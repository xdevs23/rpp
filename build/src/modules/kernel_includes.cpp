/*******************************************************************************
 *
 * MIT License
 *
 * Copyright (c) 2019 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *******************************************************************************/
#include <algorithm>
#include <map>
#include <hip/rpp/kernel.hpp>
#include <hip/rpp/stringutils.hpp>

namespace rpp {

const std::map<std::string, std::string>& kernel_includes()
{
    static const std::map<std::string, std::string> data{};
    return data;
}
std::string GetKernelInc(std::string key)
{
    auto it = kernel_includes().find(key);
    if(it == kernel_includes().end())
        RPP_THROW("Failed to load kernel source: " + key);

    return it->second;
}
std::vector<std::string> GetKernelIncList()
{
    std::vector<std::string> keys;
    auto m = kernel_includes();
    std::transform(m.begin(),
                   m.end(),
                   std::back_inserter(keys),
                   [](decltype(m)::value_type const& pair) { return pair.first; });
    return keys;
}
} // namespace rpp
