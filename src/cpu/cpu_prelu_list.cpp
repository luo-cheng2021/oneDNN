/*******************************************************************************
* Copyright 2020-2021 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cpu/cpu_engine.hpp"
#include "cpu/ref_prelu.hpp"

#if DNNL_X64
#include "cpu/x64/prelu/jit_prelu_backward.hpp"
#include "cpu/x64/prelu/jit_prelu_forward.hpp"

using namespace dnnl::impl::cpu::x64;
#endif

namespace dnnl {
namespace impl {
namespace cpu {

namespace {
using namespace dnnl::impl::data_type;

// clang-format off
const impl_list_item_t impl_list[] = {
        CPU_INSTANCE_X64(jit_prelu_fwd_t)
#ifdef ENABLE_UNUSED_PRIM
        CPU_INSTANCE_X64(jit_prelu_bwd_t)
#endif
        CPU_INSTANCE(ref_prelu_fwd_t)
#ifdef ENABLE_UNUSED_PRIM
        CPU_INSTANCE(ref_prelu_bwd_t)
#endif
        /* eol */
        nullptr,
};
// clang-format on
} // namespace

const impl_list_item_t *get_prelu_impl_list(const prelu_desc_t *desc) {
    UNUSED(desc);
    return impl_list;
}

} // namespace cpu
} // namespace impl
} // namespace dnnl
