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
/**********************************************************************
Copyright (c)2017 Advanced Micro Devices, Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted
provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and
the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions
and the following disclaimer in the documentation and/or
 other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
********************************************************************/

#ifndef MLO_INTERNAL_H_
#define MLO_INTERNAL_H_

// Header Files
#ifndef NOMINMAX
#define NOMINMAX // stupid windows.h confused with min() macros in std namespace
#endif

#include <miopen/config.h>

#if MIOPEN_BACKEND_OPENCL
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif
#endif

#ifdef __APPLE__
#include <mach/mach_time.h> // for mach_absolute_time() and friends
#endif

#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <map>
#include <string>
#include <limits>
#include <algorithm> // std::find  and std::min std::maxx

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <numeric>
#include <cstdint>
#include <tuple>

#ifdef _WIN32
#include <io.h>
#include <windows.h>
// #include <BaseTsd.h>
#include <direct.h>
#define snprintf _snprintf
#define vsnprintf _vsnprintf
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
//#ifndef getcwd
// #define getcwd _getcwd
//#endif
typedef unsigned int uint;

#ifndef getcwd
#define getcwd _getcwd
#endif

#else // !WIN32 so Linux and APPLE
#include <climits>
#include <unistd.h>
#include <cstdbool>
#include <sys/time.h>
#include <sys/resource.h>
using __int64 = long long;
#ifndef fopen_s
#define fopen_s(file, fileName, mode) ((*(file)) = fopen((fileName), (mode))) == nullptr
#endif

#endif

using mlo_kernel_info = std::tuple<const std::string,
                                   const std::string,
                                   const std::string,
                                   const std::vector<size_t>,
                                   const std::vector<size_t>>;

#if MIOPEN_BACKEND_OPENCL
#include <miopen/oclkernel.hpp>
#include <miopen/clhelper.hpp>
#include <miopen/ocldeviceinfo.hpp>
#endif
#include <miopen/tensor.hpp>
#include <miopen/handle.hpp>

inline int mloLg2(int v)
{
    auto ret = static_cast<int>(std::ceil(std::log(v) / std::log(2)));
    return (ret);
}

inline int AlignUp(int val, unsigned step)
{
    assert(step > 0);
    return ((val + step - 1) / step) * step;
}

enum rocm_meta_version
{
    V1,
    V2,
    V3
};

namespace miopen {

/// A leftover of the legacy design, houses problem config,
/// environmental context (e.g. HW/SW platform) and solver-specific state.
///
/// TODO: These three entities should be made separate.
class ConvolutionContext
{
    public:
    bool n_passes = false;

    bool forward;
    bool do_search           = false;
    bool save_srch_req       = false;
    bool assembler_available = false;
    bool use_binaries        = true;
    std::string weights_layout;
    std::string in_layout;
    std::string in_data_type;
    std::string out_data_type;
    std::string out_layout;
    size_t bot_sz, top_sz, weights_sz, bias_sz;
    int pad0, pad1;
    int kernel_stride0, kernel_stride1;
    int kernel_size0, kernel_size1;
    int kernal_dilation0, kernal_dilation1;
    int deconvolution;
    int n_inputs, n_outputs;
    int in_width, in_height;
    int out_width, out_height;
    int in_stride, out_stride;
    int in_channel_stride, in_batch_stride;
    int out_channel_stride, out_batch_stride;
    int batch_sz;
    int bias;
    int n_timer_iter = 0;
    rocm_meta_version rmv;
    std::string general_compile_options;

    ConvolutionContext()
        : forward(),
          bot_sz(),
          top_sz(),
          weights_sz(),
          bias_sz(),
          pad0(),
          pad1(),
          kernel_stride0(),
          kernel_stride1(),
          kernel_size0(),
          kernel_size1(),
          kernal_dilation0(),
          kernal_dilation1(),
          deconvolution(),
          n_inputs(),
          n_outputs(),
          in_width(),
          in_height(),
          out_width(),
          out_height(),
          in_stride(),
          out_stride(),
          in_channel_stride(),
          in_batch_stride(),
          out_channel_stride(),
          out_batch_stride(),
          batch_sz(),
          bias(),
          rmv(),
          _stream()
    {
    }

    inline Handle& GetStream() const { return *_stream; }
    inline void SetStream(Handle* stream) { _stream = stream; }

    private:
    Handle* _stream;
};

namespace solver {
class ConvSolution;
class Solver;
} // namespace solver

} // namespace miopen

class mlo_construct_direct2D
{
    public:
    virtual const std::vector<std::reference_wrapper<const miopen::solver::Solver>>&
    SolverStore() const;
    void mloUseSolution(const miopen::solver::ConvSolution& s);

    mlo_construct_direct2D(int dir, bool do_bias = false)
    {
        _search_params.forward = dir;
        _do_backward           = false;

        //#if !(defined(__APPLE__) || defined(__MACOSX))
        //	_gen_comp_options = std::string(" -cl-std=CL2.0 ");
        //#endif
        _in_tile0 = (_search_params.in_width < 12) ? 8 : 16; //(_in_width < 12) ? 8 : (_in_width <
                                                             // 24 || (_in_width > 32 && _in_width <
        // 48)) ? 16 : 32; // size of input data
        // per ALU plane
        _in_tile1 = (_search_params.in_height < 12) ? 8 : 16; // (_in_height < 12) ? 8 : (_in_height
                                                              // < 24 || (_in_height > 32 &&
                                                              // _in_height < 48)) ? 16 : 32; //
                                                              // size of input data per ALU plane

        _grp_tile0 = _in_tile0;
        _grp_tile1 = _in_tile1;

        _out_pix_tile0 = 2; // size of ouptput tile per wk-item (ALU))
        _out_pix_tile1 = 4; //

        _n_out_pix_tiles = 2; // # output pixel tiles per wk-item (ALU)
        _n_in_data_tiles = 4; // # of blocks of different inputs in LDS

        _n_stacks                       = 1; // # of diff stacks (part of batch).
        _search_params.bias             = (do_bias) ? 1 : 0;
        _search_params.pad0             = 1;
        _search_params.pad1             = 1;
        _search_params.kernel_size0     = 3;
        _search_params.kernel_size1     = 3;
        _search_params.kernel_stride0   = 1;
        _search_params.kernel_stride1   = 1;
        _search_params.kernal_dilation0 = 1;
        _search_params.kernal_dilation1 = 1;
        _search_params.deconvolution    = 0;
        _search_params.bot_sz           = 0; // bytes
        _search_params.top_sz           = 0; // bytes
        _search_params.weights_sz       = 0; // bytes
        _search_params.bias_sz          = 0; // bytes

        _workspce_sz = 0;

        _small         = true;
        _copy_input    = false;
        _new_in_width  = 0;
        _new_in_height = 0;
        _new_in_sz     = 0;
    }

    virtual ~mlo_construct_direct2D() = default;
    /*
    * major interface
    * it has to be called only after
    * convolutional parmeters, input, output and weight tesnor have been set
    *
    * constructs compiler option
    *
    * selects kernel file and name
    * covers genrinc forward convolution:
    * arbitrary combination of kerenl sizes, strides
    */

    /// \todo The function is never called through the vtable. Remove "virtual". Consider moving
    /// into ctor, if possible.
    virtual int mloConstruct();

    /*
    * returns parameter values that are compiled in legacy kernels for kernels using them as
    * arguments.
    */
    inline void getCompiledInParameters(
        int* N, int* C, int* H, int* W, int* K, int* n_groups, int* R = nullptr, int* S = nullptr)
    {
        assert(N && C && H && W && K && n_groups);

        *N        = _search_params.batch_sz;
        *C        = _search_params.n_inputs;
        *H        = _search_params.in_height;
        *W        = _search_params.in_width;
        *K        = _search_params.n_outputs;
        *n_groups = _search_params.GetStream().GetMaxComputeUnits();
        if(R)
        {
            *R = _search_params.kernel_size1;
        } // R is height (sic!)
        if(S)
        {
            *S = _search_params.kernel_size0;
        }
    }

    /*
    * returns kernel file name without location
    */
    inline std::string getKernelFile() const { return (_kernel_file); }
    /*
    * retuns kerner/shader name
    */
    inline std::string getKernelName() const { return (_kernel_name); }
    /*
    * return set of compile options
    */

    inline const std::string& getCompilerOptions() const { return (_comp_options); }
    /*
    *  return a local working configuration
    */
    inline const std::vector<size_t>& getLocalWkSize() const { return (_l_wk); }
    /*
    * return a global working configuration
    */
    inline const std::vector<size_t>& getGlobalWkSize() const { return (_g_wk); }

    /*
    * get common compiler options
    */
    inline const std::string& getGeneralCompOptions() const
    {
        return (_search_params.general_compile_options);
    }

    /*
    * get info for all kernels of the layer
    * std::string _kernel_name;
    * std::string _kernel_file;
    * std::string _comp_options;
    * std::vector<size_t> _g_wk;
    * std::vector<size_t> _l_wk;
    */

    inline const std::vector<mlo_kernel_info>& getKernelsInfo() const
    {
        return (_mlo_kernels_info);
    }

    /*
    * return direction: true - forward, false - backward
    */
    inline bool isForwardDirection() const { return (_search_params.forward == 1); }

    /*
    * get workspace size
    */
    inline size_t getWorkSpaceSzBytes() const { return (_workspce_sz); }
    /*
    *  is bias incuded
    */

    inline bool doBias() const { return (_search_params.bias == 1); }

    /*
    * set a number of iteration for thwe wall clock performance meaturement
    */

    inline void setTimerIter(int n_timer_iter) { _search_params.n_timer_iter = n_timer_iter; }

    /*
    * set library stream
    */
    inline void setStream(miopen::Handle* stream) { _search_params.SetStream(stream); }

    /*
    * set ocl Kernels path
    */
    inline void setKernelPath(const std::string& kernel_path) { _kernel_path = kernel_path; }

    /*
    * set convolutional parameters
    */
    inline void setConvDescr(int u_padding,
                             int v_padding,
                             int u_stride,
                             int v_stride,
                             int /*u_upstride*/,
                             int /*v_upstride*/
                             )
    {
        _search_params.pad1           = u_padding;
        _search_params.pad0           = v_padding;
        _search_params.kernel_stride0 = u_stride;
        _search_params.kernel_stride1 = v_stride;
    }

    /*
    * set weights tensor
    */
    inline void setWeightsDescr(const std::string& layout,
                                const std::string& data_type,
                                int batch,
                                int depth,
                                int height,
                                int width,
                                int batch_stride,
                                int channel_stride,
                                int stride,
                                int w_stride)
    {
        _search_params.kernel_size0 = width;
        _search_params.kernel_size1 = height;
        int data_len                = (data_type == "FP32" ? 4 : 8);
        size_t size                 = (layout == "NCHW")
                          ? batch * depth * height * width * data_len
                          : batch * batch_stride * channel_stride * stride * w_stride * data_len;
        _search_params.weights_sz = size;
    }

    /*
    * set output tensor
    */
    inline void setOutputDescr(const std::string& layout,
                               const std::string& data_type,
                               int batch,
                               int depth,
                               int height,
                               int width,
                               int batch_stride,
                               int channel_stride,
                               int stride,
                               int w_stride)
    {
        _search_params.batch_sz = batch;
        int data_len            = (data_type == "FP32" ? 4 : 8);
        size_t size             = (layout == "NCHW")
                          ? batch * depth * height * width * data_len
                          : batch * batch_stride * channel_stride * stride * w_stride * data_len;
        if(_search_params.forward)
        {

            _search_params.out_width          = width;
            _search_params.out_height         = height;
            _search_params.n_outputs          = depth;
            _search_params.out_batch_stride   = batch_stride;
            _search_params.out_channel_stride = channel_stride;
            _search_params.out_stride         = stride;
            _search_params.top_sz             = size;
            _search_params.out_layout         = layout;
            _search_params.out_data_type      = data_type;
        }
        else
        {
            _search_params.in_width          = width;
            _search_params.in_height         = height;
            _search_params.n_inputs          = depth;
            _search_params.in_batch_stride   = batch_stride;
            _search_params.in_channel_stride = channel_stride;
            _search_params.in_stride         = stride;
            _search_params.bot_sz            = size;
            _search_params.in_layout         = layout;
            _search_params.in_data_type      = data_type;
            //			_tens_layout = layout;
            //			_tens_data_format = data_type;
        }
    }

    /*
    *  set input tensor
    */

    inline void setInputDescr(const std::string& layout,
                              const std::string& data_type,
                              int batch,
                              int depth,
                              int height,
                              int width,
                              int batch_stride,
                              int channel_stride,
                              int stride,
                              int w_stride)
    {
        _search_params.batch_sz = batch;
        int data_len            = (data_type == "FP32" ? 4 : 8);
        size_t size             = (layout == "NCHW")
                          ? batch * depth * height * width * data_len
                          : batch * batch_stride * channel_stride * stride * w_stride * data_len;
        if(_search_params.forward)
        {

            _search_params.in_width          = width;
            _search_params.in_height         = height;
            _search_params.n_inputs          = depth;
            _search_params.in_batch_stride   = batch_stride;
            _search_params.in_channel_stride = channel_stride;
            _search_params.in_stride         = stride;
            _search_params.bot_sz            = size;
            _search_params.in_layout         = layout;
            _search_params.in_data_type      = data_type;
            //			_tens_layout = layout;
            //			_tens_data_format = data_type;
        }
        else
        {
            _search_params.out_width          = width;
            _search_params.out_height         = height;
            _search_params.n_outputs          = depth;
            _search_params.out_batch_stride   = batch_stride;
            _search_params.out_channel_stride = channel_stride;
            _search_params.out_stride         = stride;
            _search_params.top_sz             = size;
            _search_params.out_layout         = layout;
            _search_params.out_data_type      = data_type;
        }

        _search_params.bias_sz = (_search_params.bias) ? _search_params.n_outputs * data_len : 0;
    }

    /*
    * set top tensor
    */
    void setTopDescr(const std::string& layout,
                     const std::string& data_type,
                     int batch,
                     int depth,
                     int height,
                     int width,
                     int batch_stride,
                     int channel_stride,
                     int stride,
                     int w_stride)
    {
        _search_params.batch_sz = batch;
        int data_len            = (data_type == "FP32" ? 4 : 8);
        size_t size             = (layout == "NCHW")
                          ? batch * depth * height * width * data_len
                          : batch * batch_stride * channel_stride * stride * w_stride * data_len;

        _search_params.out_width          = width;
        _search_params.out_height         = height;
        _search_params.n_outputs          = depth;
        _search_params.out_batch_stride   = batch_stride;
        _search_params.out_channel_stride = channel_stride;
        _search_params.out_stride         = stride;
        _search_params.top_sz             = size;
        _search_params.out_layout         = layout;
        _search_params.out_data_type      = data_type;
        _search_params.bias_sz = (_search_params.bias) ? _search_params.n_outputs * data_len : 0;
    }

    /*
    *  set bot tensor
    */

    void setBotDescr(const std::string& layout,
                     const std::string& data_type,
                     int batch,
                     int depth,
                     int height,
                     int width,
                     int batch_stride,
                     int channel_stride,
                     int stride,
                     int w_stride)
    {
        _search_params.batch_sz = batch;
        int data_len            = (data_type == "FP32" ? 4 : 8);
        size_t size             = (layout == "NCHW")
                          ? batch * depth * height * width * data_len
                          : batch * batch_stride * channel_stride * stride * w_stride * data_len;

        _search_params.in_width          = width;
        _search_params.in_height         = height;
        _search_params.n_inputs          = depth;
        _search_params.in_batch_stride   = batch_stride;
        _search_params.in_channel_stride = channel_stride;
        _search_params.in_stride         = stride;
        _search_params.bot_sz            = size;
        _search_params.in_layout         = layout;
        _search_params.in_data_type      = data_type;
        //			_tens_layout = layout;
        //			_tens_data_format = data_type;
    }

    /*
    * set top df tensor
    */
    void setTopDfDescr(const std::string& layout,
                       const std::string& data_type,
                       int batch,
                       int depth,
                       int height,
                       int width,
                       int batch_stride,
                       int channel_stride,
                       int stride,
                       int w_stride)
    {
        _search_params.batch_sz = batch;
        int data_len            = (data_type == "FP32" ? 4 : 8);
        size_t size             = (layout == "NCHW")
                          ? batch * depth * height * width * data_len
                          : batch * batch_stride * channel_stride * stride * w_stride * data_len;

        _out_df_width            = width;
        _out_df_height           = height;
        _search_params.n_outputs = depth;
        _out_df_batch_stride     = batch_stride;
        _out_df_channel_stride   = channel_stride;
        _out_df_stride           = stride;
        _top_df_sz               = size;
        _out_df_layout           = layout;
        _out_df_data_type        = data_type;
    }

    /*
    *  set bot df tensor
    */

    void setBotDfDescr(const std::string& layout,
                       const std::string& data_type,
                       int batch,
                       int depth,
                       int height,
                       int width,
                       int batch_stride,
                       int channel_stride,
                       int stride,
                       int w_stride)
    {
        _search_params.batch_sz = batch;
        int data_len            = (data_type == "FP32" ? 4 : 8);
        size_t size             = (layout == "NCHW")
                          ? batch * depth * height * width * data_len
                          : batch * batch_stride * channel_stride * stride * w_stride * data_len;

        _in_df_width            = width;
        _in_df_height           = height;
        _search_params.n_inputs = depth;
        _in_df_batch_stride     = batch_stride;
        _in_df_channel_stride   = channel_stride;
        _in_df_stride           = stride;
        _bot_df_sz              = size;
        _in_df_layout           = layout;
        _in_df_data_type        = data_type;
    }

    /*
    *  indicate the need for backward pass
    */
    inline void doBackward(bool do_bwd) { _do_backward = do_bwd; }
    /*
    * need for backward pass?
    */
    inline bool doBackward() const { return (_do_backward); }

    /*
    *  allow the search for the best possible solution
    */
    inline void doSearch(bool do_search) { _search_params.do_search = do_search; }
    /*
    * is search set?
    */
    inline bool doSearch() const { return (_search_params.do_search); }

    /*
    * allow to save the missing configuraion in the search request file for an offline search
    */
    inline void saveSearchRequest(bool save_req) { _search_params.save_srch_req = save_req; }
    /*
    * set common compiler options
    */
    inline void setGeneralCompOptions(const std::string& options)
    {
        _search_params.general_compile_options += options;
    }

    // MD: Hack to get the key outside of mlo_internal
    int mloBuildConf_Key(std::string& conf_key) const;

    inline bool doCopyInput() const { return (_copy_input); }

    // MD: Where is this being used?
    void getNewInputDescr(std::string& layout,
                          std::string& data_type,
                          int& batch,
                          int& depth,
                          int& height,
                          int& width,
                          int& batch_stride,
                          int& channel_stride,
                          int& stride,
                          int& w_stride);
    // TEMP
    int mloConstructSP2D();

    size_t setInputDescFromMLDesc(const miopen::TensorDescriptor& input_tensor);
    size_t setOutputDescFromMLDesc(const miopen::TensorDescriptor& output_tensor);
    size_t setWeightDescFromMLDesc(const miopen::TensorDescriptor& weight_tensor);

    bool mloIsCompilerWorkarounds() const;
    bool mloIsFastBinaryWinograd3x3U() const;

    inline void mloCopyTo(miopen::ConvolutionContext& params) const /// TODO: get rid of this
    {
        params = _search_params;
    }

    protected:
    bool mloIsAmdOpenclRocm(rocm_meta_version& rmv) const;

    int mloConstructBwd() { return (0); }
    int mloConstructFwd() { return (0); }

    //	int mloBuildConf_Key(std::string & conf_key) const;

    protected:
    miopen::ConvolutionContext _search_params;

    int _in_df_width          = 0;
    int _in_df_height         = 0;
    int _in_df_batch_stride   = 0;
    int _in_df_channel_stride = 0;
    int _in_df_stride         = 0;
    std::string _in_df_layout;
    std::string _in_df_data_type;

    int _out_df_width          = 0;
    int _out_df_height         = 0;
    int _out_df_batch_stride   = 0;
    int _out_df_channel_stride = 0;
    int _out_df_stride         = 0;
    std::string _out_df_layout;
    std::string _out_df_data_type;

    // SP

    bool _small;
    bool _copy_input;
    int _new_in_height;
    int _new_in_width;
    int _new_in_batch_stride   = 0;
    int _new_in_channel_stride = 0;
    int _new_in_stride         = 0;
    size_t _new_in_sz;
    bool _do_backward;

    // FIX IT
    //	int _weights_height;
    //	int _weights_stride;
    std::string _weight_data_type;
    //
    //	std::string _tens_layout;
    //	std::string _tens_data_format;

    int _in_tile0        = 0; // size of in-tile in local memory
    int _in_tile1        = 0; // size of in-tile in local memory
    int _grp_tile0       = 0; // total number ALUs per group
    int _grp_tile1       = 0; // total number ALUs per group
    int _out_pix_tile0   = 0; // # of generated pixels per output per wk-item  (ALU)
    int _out_pix_tile1   = 0; // # of generated pixels per output per wk-item  (ALU)
    int _n_out_pix_tiles = 0; // # output pixel tiles per wk-item (ALU)
    int _n_in_data_tiles = 0; // # of blocks of different inputs in LDS
    int _n_stacks        = 0; // # of diff stacks (part of batch).
    std::string _comp_options;
    std::string _kernel_file;
    std::string _kernel_name;
    std::vector<size_t> _l_wk;
    std::vector<size_t> _g_wk;

    // more than 1 kerenls per stage
    std::vector<mlo_kernel_info> _mlo_kernels_info;

    bool _gen  = false; // genral case
    int _quiet = 0;
    std::string _kernel_path;
    // local memory size per group
    size_t _dev_local_mem_sz = 0;
    // wave size
    int _hw_wave_sz = 0;
    // cl_queue
    size_t _bot_df_sz = 0; // bytes
    size_t _top_df_sz = 0; // bytes

    size_t _workspce_sz;

    unsigned int _n_groups{};
};

/*
* backward with regard to weights construction
*/

class mlo_construct_BwdWrW2D : public mlo_construct_direct2D
{
    public:
    mlo_construct_BwdWrW2D(int dir, bool do_bias = false) : mlo_construct_direct2D(dir, do_bias) {}

    bool mloIsCompilerWorkarounds() const;
    int mloMultiStep();
    const std::vector<std::reference_wrapper<const miopen::solver::Solver>>&
    SolverStore() const override;
};

/*
* winograd algorithm
*/

class mlo_construct_winograd : public mlo_construct_direct2D
{
    public:
    mlo_construct_winograd(int dir, bool do_bias = false) : mlo_construct_direct2D(dir, do_bias) {}

    const std::vector<std::reference_wrapper<const miopen::solver::Solver>>&
    SolverStore() const override;
};

#define MLO_POOLING_OP_AVE 0
#define MLO_POOLING_OP_MAX 1
#define MLO_POOLING_OP_STC 2

class mlo_construct_pooling2D : public mlo_construct_direct2D
{
    public:
    mlo_construct_pooling2D(int dir) : mlo_construct_direct2D(dir)
    {
        _pooling_method = MLO_POOLING_OP_MAX;
        _NAN_option     = 0;
    }

    inline void setPoolingDescr(int pooling_method = MLO_POOLING_OP_MAX,
                                int windowHeight   = 3,
                                int windowWidth    = 3,
                                int padding_v      = 0,
                                int padding_h      = 0,
                                int stride_v       = 2,
                                int stride_h       = 2,
                                int NAN_opt        = 0)
    {
        _pooling_method               = pooling_method;
        _search_params.pad1           = padding_v;
        _search_params.pad0           = padding_h;
        _search_params.kernel_size1   = windowHeight;
        _search_params.kernel_size0   = windowWidth;
        _search_params.kernel_stride1 = stride_v;
        _search_params.kernel_stride0 = stride_h;
        _NAN_option                   = NAN_opt;
    }

    inline void getPoolingDescr(int& /*pooling_method*/,
                                int& windowHeight,
                                int& windowWidth,
                                int& padding_v,
                                int& padding_h,
                                int& stride_v,
                                int& stride_h,
                                int& NAN_opt) const
    {
        padding_v    = _search_params.pad1;
        padding_h    = _search_params.pad0;
        windowHeight = _search_params.kernel_size1;
        windowWidth  = _search_params.kernel_size0;
        stride_v     = _search_params.kernel_stride1;
        stride_h     = _search_params.kernel_stride0;
        NAN_opt      = _NAN_option;
    }

    inline int getPoolingMethod() const { return (_pooling_method); }
    int mloConstruct() override;

    protected:
    int _pooling_method;
    int _NAN_option;
    int mloConstructFwd();
    int mloConstructBwd();
};

#define MLO_LRN_WITHIN_CHANNEL 0
#define MLO_LRN_ACROSS_CHANNELS 1

class mlo_construct_norm : public mlo_construct_direct2D
{
    public:
    mlo_construct_norm(int dir) : mlo_construct_direct2D(dir) {}

    inline void setNormDescr(
        int norm_region, int norm_area, double normAlpha, double normBeta, double normK = 1.)
    {
        _norm_region = norm_region;
        _norm_area   = norm_area;
        _normAlpha   = normAlpha;
        _normBeta    = normBeta;
        _normK       = normK;
    }

    inline void getNormDescr(int& norm_region,
                             int& norm_area,
                             double& normAlpha,
                             double& normBeta,
                             double& normK,
                             double& alphaoverarea) const
    {
        norm_region   = _norm_region;
        norm_area     = _norm_area;
        normAlpha     = _normAlpha;
        normBeta      = _normBeta;
        normK         = _normK;
        alphaoverarea = (_norm_region == MLO_LRN_ACROSS_CHANNELS)
                            ? _normAlpha / _norm_area
                            : _normAlpha / (_norm_area * _norm_area);
    }

    int mloConstruct() override;

    protected:
    int mloConstructFwd();
    int mloConstructBwd();
    int _norm_region  = 0;
    int _norm_area    = 0;
    double _normAlpha = 0.0;
    double _normBeta  = 0.0;
    double _normK     = 0.0;
};

#define MLO_NEURON_PASTHRU 0                       // x
#define MLO_NEURON_LOGISTIC MLO_NEURON_PASTHRU + 1 //	1 / (1 + e^-x)	//Sigmoid
#define MLO_NEURON_TANH MLO_NEURON_LOGISTIC + 1    //	a * tanh( b * x)
#define MLO_NEURON_RELU MLO_NEURON_TANH + 1        //	max(0, x)
#define MLO_NEURON_BRELU MLO_NEURON_RELU + 1       //	min(a, max(0, x))
#define MLO_NEURON_SOFTRELU \
    MLO_NEURON_BRELU + 1                       //	log(1 + e^x)   // bonomial normal log likelihood
#define MLO_NEURON_ABS MLO_NEURON_SOFTRELU + 1 //	abs(x)
#define MLO_NEURON_SQUARE MLO_NEURON_ABS + 1   //	x^2
#define MLO_NEURON_SQR MLO_NEURON_SQUARE + 1   //	sqr(x)
#define MLO_NEURON_LINEAR MLO_NEURON_SQR + 1   //	a + b * x
#define MLO_NEURON_POWER MLO_NEURON_LINEAR + 1 // (a + b * x ) ^power
#define MLO_NEURON_TOTAL MLO_NEURON_POWER + 1

class mlo_construct_neuron : public mlo_construct_direct2D
{
    public:
    mlo_construct_neuron(int dir) : mlo_construct_direct2D(dir)
    {
        _neuron_type = 0;
        _power       = 0;
        _scale       = 1;
        _shift       = 0;
    }

    inline void setNeuronDescr(int neuron_type, double power, double scale, double shift)
    {
        _neuron_type = neuron_type;
        _power       = power;
        _scale       = scale;
        _shift       = shift;
    }

    inline void getNeuronDescr(int& neuron_type, double& power, double& scale, double& shift) const
    {
        neuron_type = _neuron_type;
        power       = _power;
        scale       = _scale;
        shift       = _shift;
    }

    int mloConstruct() override;

    protected:
    int mloConstructFwd();
    int mloConstructBwd();
    int _neuron_type;
    double _power;
    double _scale;
    double _shift;
};

#endif
