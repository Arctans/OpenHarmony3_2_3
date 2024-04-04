/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
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
#ifndef ZIP_OUTPUT_FACTORY_H
#define ZIP_OUTPUT_FACTORY_H

#include "executor_factory.h"

namespace OHOS {
namespace HiviewDFX {
class ZipOutputFactory : public ExecutorFactory {
public:
    std::shared_ptr<HidumperExecutor> CreateExecutor();
};
} // namespace HiviewDFX
} // namespace OHOS
#endif // ZIP_OUTPUT_FACTORY_H
