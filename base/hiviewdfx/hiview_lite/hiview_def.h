/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
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

#ifndef HOS_LITE_HIVIEW_DEF_H
#define HOS_LITE_HIVIEW_DEF_H

#include "ohos_types.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#define HIVIEW_SERVICE                     "hiview"
#define LOG_INFO_HEAD                      0xEC
#define EVENT_INFO_HEAD                    0xEA
#define MS_PER_SECOND                      1000
#define SECONDS_PER_DAY                    86400
#define SECONDS_PER_HOUR                   3600
#define SECONDS_PER_MINUTE                 60
#define LOG_FMT_MAX_LEN                    128
#define LOG_CONTENT_MAX_LEN                96
#define LOG_MODULE_NAME_LEN                16
#define LOG_TIME_STR_SIZE                  10
#define TAIL_LINE_BREAK                    2
#define READ_FILE_BUF_MAX_SIZE             1024

#pragma pack(1)
typedef struct {
    uint8 id;
    const char *name; /* LOG_MODULE_NAME_LEN */
} HiLogModuleInfo;
#pragma pack()

typedef struct {
    uint8 last : 1;   /* Indicates whether the last parameter. */
    uint8 id : 4;
    uint8 len : 3;
} HiEventTag;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef HOS_LITE_HIVIEW_DEF_H */
