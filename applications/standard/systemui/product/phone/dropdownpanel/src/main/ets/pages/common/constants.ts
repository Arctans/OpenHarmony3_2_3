/*
 * Copyright (c) 2021-2022 Huawei Device Co., Ltd.
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

export default class Constants {
  static readonly TOUCHTYPE_DOWN = 0;
  static readonly TOUCHTYPE_UP = 1;
  static readonly TOUCHTYPE_MOVE = 2;
  static readonly WEEKDAY_LIST = [
    $r('app.string.sunday'),
    $r('app.string.monday'),
    $r('app.string.tuesday'),
    $r('app.string.wednesday'),
    $r('app.string.thursday'),
    $r('app.string.friday'),
    $r('app.string.saturday')
  ];
  static readonly DIGITS = 10;
  static readonly MARK_MONTH = 0;
  static readonly MARK_DAY = 1;
  static readonly QUICKLY_SETTING_H = 83;
}