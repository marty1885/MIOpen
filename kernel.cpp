/*******************************************************************************
 *
 * MIT License
 *
 * Copyright (c) 2017 Advanced Micro Devices, Inc.
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
#include "miopen_kernels.h"
#include <algorithm>
#include <map>
#include <miopen/kernel.hpp>
#include <miopen/stringutils.hpp>

namespace miopen {

const std::map<std::string, std::string>& kernels()
{
    static const std::map<std::string, std::string> data{    { "MIOPENCHECKNUMERICS", std::string(reinterpret_cast<const char*>(MIOPENCHECKNUMERICS), MIOPENCHECKNUMERICS_SIZE) },
    { "MIOPENBATCHNORMFWDTRAINSPATIAL", std::string(reinterpret_cast<const char*>(MIOPENBATCHNORMFWDTRAINSPATIAL), MIOPENBATCHNORMFWDTRAINSPATIAL_SIZE) },
    { "MIOPENBATCHNORMFWDTRAINPERACT", std::string(reinterpret_cast<const char*>(MIOPENBATCHNORMFWDTRAINPERACT), MIOPENBATCHNORMFWDTRAINPERACT_SIZE) },
    { "MIOPENBATCHNORMFWDINFERSPATIAL", std::string(reinterpret_cast<const char*>(MIOPENBATCHNORMFWDINFERSPATIAL), MIOPENBATCHNORMFWDINFERSPATIAL_SIZE) },
    { "MIOPENBATCHNORMFWDINFERPERACT", std::string(reinterpret_cast<const char*>(MIOPENBATCHNORMFWDINFERPERACT), MIOPENBATCHNORMFWDINFERPERACT_SIZE) },
    { "MIOPENBATCHNORMBWDSPATIAL", std::string(reinterpret_cast<const char*>(MIOPENBATCHNORMBWDSPATIAL), MIOPENBATCHNORMBWDSPATIAL_SIZE) },
    { "MIOPENBATCHNORMBWDPERACT", std::string(reinterpret_cast<const char*>(MIOPENBATCHNORMBWDPERACT), MIOPENBATCHNORMBWDPERACT_SIZE) },
    { "MIOPENCONVDIRUNI", std::string(reinterpret_cast<const char*>(MIOPENCONVDIRUNI), MIOPENCONVDIRUNI_SIZE) },
    { "MIOPENCONVDIRGENFWD", std::string(reinterpret_cast<const char*>(MIOPENCONVDIRGENFWD), MIOPENCONVDIRGENFWD_SIZE) },
    { "MIOPENLRNBWD", std::string(reinterpret_cast<const char*>(MIOPENLRNBWD), MIOPENLRNBWD_SIZE) },
    { "MIOPENLRNFWD", std::string(reinterpret_cast<const char*>(MIOPENLRNFWD), MIOPENLRNFWD_SIZE) },
    { "MIOPENNEURON", std::string(reinterpret_cast<const char*>(MIOPENNEURON), MIOPENNEURON_SIZE) },
    { "MIOPENPOOLING", std::string(reinterpret_cast<const char*>(MIOPENPOOLING), MIOPENPOOLING_SIZE) },
    { "MIOPENPOOLINGBWD", std::string(reinterpret_cast<const char*>(MIOPENPOOLINGBWD), MIOPENPOOLINGBWD_SIZE) },
    { "MIOPENCONVDIRUNIC", std::string(reinterpret_cast<const char*>(MIOPENCONVDIRUNIC), MIOPENCONVDIRUNIC_SIZE) },
    { "MIOPENCONV1X1S", std::string(reinterpret_cast<const char*>(MIOPENCONV1X1S), MIOPENCONV1X1S_SIZE) },
    { "MIOPENCONV1X1J1", std::string(reinterpret_cast<const char*>(MIOPENCONV1X1J1), MIOPENCONV1X1J1_SIZE) },
    { "MIOPENCONV1X1J1_STRIDE", std::string(reinterpret_cast<const char*>(MIOPENCONV1X1J1_STRIDE), MIOPENCONV1X1J1_STRIDE_SIZE) },
    { "MIOPENSOFTMAX", std::string(reinterpret_cast<const char*>(MIOPENSOFTMAX), MIOPENSOFTMAX_SIZE) },
    { "MIOPENCONVD3X3", std::string(reinterpret_cast<const char*>(MIOPENCONVD3X3), MIOPENCONVD3X3_SIZE) },
    { "MIOPENUTILKERNELS", std::string(reinterpret_cast<const char*>(MIOPENUTILKERNELS), MIOPENUTILKERNELS_SIZE) },
    { "MIOPENUTILKERNELS2", std::string(reinterpret_cast<const char*>(MIOPENUTILKERNELS2), MIOPENUTILKERNELS2_SIZE) },
    { "MIOPENCONVBWDWRWS2", std::string(reinterpret_cast<const char*>(MIOPENCONVBWDWRWS2), MIOPENCONVBWDWRWS2_SIZE) },
    { "MIOPENCONVBWDWRW_LXG_P53", std::string(reinterpret_cast<const char*>(MIOPENCONVBWDWRW_LXG_P53), MIOPENCONVBWDWRW_LXG_P53_SIZE) },
    { "MIOPENCONVBWDWRW_LXG_5X5", std::string(reinterpret_cast<const char*>(MIOPENCONVBWDWRW_LXG_5X5), MIOPENCONVBWDWRW_LXG_5X5_SIZE) },
    { "MIOPENCONVBWDWRW1X1", std::string(reinterpret_cast<const char*>(MIOPENCONVBWDWRW1X1), MIOPENCONVBWDWRW1X1_SIZE) },
    { "MIOPENCONVBWDWRW1X1MMAP", std::string(reinterpret_cast<const char*>(MIOPENCONVBWDWRW1X1MMAP), MIOPENCONVBWDWRW1X1MMAP_SIZE) },
    { "MIOPENCONVFWD_LXL_11", std::string(reinterpret_cast<const char*>(MIOPENCONVFWD_LXL_11), MIOPENCONVFWD_LXL_11_SIZE) },
    { "MIOPENCONVFFT", std::string(reinterpret_cast<const char*>(MIOPENCONVFFT), MIOPENCONVFFT_SIZE) },
    { "CONV3X3", std::string(reinterpret_cast<const char*>(CONV3X3), CONV3X3_SIZE) },
    { "CONV3X3WRW", std::string(reinterpret_cast<const char*>(CONV3X3WRW), CONV3X3WRW_SIZE) },
    { "CONV5X10U2V2F1", std::string(reinterpret_cast<const char*>(CONV5X10U2V2F1), CONV5X10U2V2F1_SIZE) },
    { "CONV5X10U2V2B1", std::string(reinterpret_cast<const char*>(CONV5X10U2V2B1), CONV5X10U2V2B1_SIZE) },
    { "CONV7X7C3H224W224K64U2V2P3Q3F1", std::string(reinterpret_cast<const char*>(CONV7X7C3H224W224K64U2V2P3Q3F1), CONV7X7C3H224W224K64U2V2P3Q3F1_SIZE) },
    { "MIOPENTENSORKERNELS", std::string(reinterpret_cast<const char*>(MIOPENTENSORKERNELS), MIOPENTENSORKERNELS_SIZE) },
    { "MIOPENTENSORSCALEKERNEL", std::string(reinterpret_cast<const char*>(MIOPENTENSORSCALEKERNEL), MIOPENTENSORSCALEKERNEL_SIZE) },
    { "CONV_U1V1_WHEEL_ALPHA_V8_4_4_GFX803", std::string(reinterpret_cast<const char*>(CONV_U1V1_WHEEL_ALPHA_V8_4_4_GFX803), CONV_U1V1_WHEEL_ALPHA_V8_4_4_GFX803_SIZE) },
    { "CONV_U1V1_WHEEL_ALPHA_V8_4_4_GFX900", std::string(reinterpret_cast<const char*>(CONV_U1V1_WHEEL_ALPHA_V8_4_4_GFX900), CONV_U1V1_WHEEL_ALPHA_V8_4_4_GFX900_SIZE) },
    { "CONV_U2V2_WHEEL_ALPHA_V8_4_4_GFX803", std::string(reinterpret_cast<const char*>(CONV_U2V2_WHEEL_ALPHA_V8_4_4_GFX803), CONV_U2V2_WHEEL_ALPHA_V8_4_4_GFX803_SIZE) },
    { "CONV_U2V2_WHEEL_ALPHA_V8_4_4_GFX900", std::string(reinterpret_cast<const char*>(CONV_U2V2_WHEEL_ALPHA_V8_4_4_GFX900), CONV_U2V2_WHEEL_ALPHA_V8_4_4_GFX900_SIZE) },
    { "CONV_3X3_WHEEL_ALPHA_V7_0_3B_GFX900", std::string(reinterpret_cast<const char*>(CONV_3X3_WHEEL_ALPHA_V7_0_3B_GFX900), CONV_3X3_WHEEL_ALPHA_V7_0_3B_GFX900_SIZE) },
    { "CONV_3X3_WHEEL_ALPHA_V3_0B_GFX803_M30", std::string(reinterpret_cast<const char*>(CONV_3X3_WHEEL_ALPHA_V3_0B_GFX803_M30), CONV_3X3_WHEEL_ALPHA_V3_0B_GFX803_M30_SIZE) },
    { "CONV_3X3_WHEEL_ALPHA_V3_0B_GFX803_M21", std::string(reinterpret_cast<const char*>(CONV_3X3_WHEEL_ALPHA_V3_0B_GFX803_M21), CONV_3X3_WHEEL_ALPHA_V3_0B_GFX803_M21_SIZE) },
    { "CONV_3X3_WHEEL_ALPHA_V3_0B_GFX803_M10", std::string(reinterpret_cast<const char*>(CONV_3X3_WHEEL_ALPHA_V3_0B_GFX803_M10), CONV_3X3_WHEEL_ALPHA_V3_0B_GFX803_M10_SIZE) },
    { "MIOPENCONVBWDBIAS", std::string(reinterpret_cast<const char*>(MIOPENCONVBWDBIAS), MIOPENCONVBWDBIAS_SIZE) }};
    return data;
}

std::string GetKernelSrc(std::string name)
{
    // Use the base name of the string
    int start  = 0;
    auto slash = name.find_last_of("/\\");
    if(slash != std::string::npos)
    {
        start = slash + 1;
    }

    int len = name.size();
    auto ex = name.rfind('.');
    if(ex != std::string::npos)
    {
        len = ex - start;
    }

    auto key = name.substr(start, len);
    // Convert to uppercase
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);

    auto it = kernels().find(key);
    if(it == kernels().end())
        MIOPEN_THROW("Failed to load kernel source: " + key);

    return it->second;
}

} // namespace miopen
