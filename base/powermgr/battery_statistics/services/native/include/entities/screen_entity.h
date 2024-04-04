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

#ifndef SCREEN_ENTITY_H
#define SCREEN_ENTITY_H

#include <map>

#include "entities/battery_stats_entity.h"

namespace OHOS {
namespace PowerMgr {
class ScreenEntity : public BatteryStatsEntity {
public:
    ScreenEntity();
    ~ScreenEntity() = default;
    void Calculate(int32_t uid = StatsUtils::INVALID_VALUE) override;
    int64_t GetActiveTimeMs(StatsUtils::StatsType statsType, int16_t level = StatsUtils::INVALID_VALUE) override;
    double GetEntityPowerMah(int32_t uidOrUserId = StatsUtils::INVALID_VALUE) override;
    double GetStatsPowerMah(StatsUtils::StatsType statsType, int32_t uid = StatsUtils::INVALID_VALUE) override;
    void Reset() override;
    void DumpInfo(std::string& result, int32_t uid = StatsUtils::INVALID_VALUE) override;
    std::shared_ptr<StatsHelper::ActiveTimer> GetOrCreateTimer(StatsUtils::StatsType statsType,
        int16_t level = StatsUtils::INVALID_VALUE) override;
private:
    int64_t GetBrightnessTotalTimeMs();
    double screenPowerMah_ = StatsUtils::DEFAULT_VALUE;
    std::shared_ptr<StatsHelper::ActiveTimer> screenOnTimer_;
    std::map<int32_t, std::shared_ptr<StatsHelper::ActiveTimer>> screenBrightnessTimerMap_;
};
} // namespace PowerMgr
} // namespace OHOS
#endif // SCREEN_ENTITY_H