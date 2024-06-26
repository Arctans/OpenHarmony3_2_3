/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

#ifndef EVENT_SERVICE_ACTION_TEST_H
#define EVENT_SERVICE_ACTION_TEST_H

#include <gtest/gtest.h>
#include "event_loop.h"
#include "sys_event_db_mgr.h"
#include "hiview_global.h"
#include "hiview_platform.h"

namespace OHOS {
namespace HiviewDFX {
class EventServiceActionTest : public testing::Test {
public:
    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp();
    void TearDown();
    std::shared_ptr<EventLoop> currentLooper_ = nullptr;
    std::unique_ptr<SysEventDbMgr> sysEventDbMgrPtr;
};
} // namespace HiviewDFX
} // namespace OHOS

#endif // EVENT_SERVICE_ACTION_TEST_H