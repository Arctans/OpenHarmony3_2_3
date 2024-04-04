/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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
 */

#include "power_hdi_callback.h"
#include "hdf_base.h"

using namespace OHOS::HDI::Power::V1_0;

namespace OHOS {
namespace PowerMgr {
int32_t PowerHdiCallback::OnSuspend()
{
    return HDF_SUCCESS;
}

int32_t PowerHdiCallback::OnWakeup()
{
    return HDF_SUCCESS;
}
} // OHOS
} // PowerMgr
