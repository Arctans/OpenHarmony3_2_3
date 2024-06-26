/**
 * Copyright (c) 2022 Shenzhen Kaihong Digital Industry Development Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import router from '@system.router';
import {describe, beforeAll, beforeEach, afterEach, afterAll, it, expect} from "hypium/index"
import Utils from './Utils.ets'

export default function progressScaleCountJsunit() {
  describe('progressScaleCountTest', function () {
    beforeEach(async function (done) {
      console.info("flex beforeEach start");
      let options = {
        uri: 'pages/progress',
      }
      try {
        router.clear();
        let pages = router.getState();
        console.info("get progress state success " + JSON.stringify(pages));
        if (!("progress" == pages.name)) {
          console.info("get progress state success " + JSON.stringify(pages.name));
          let result = await router.push(options);
          await Utils.sleep(2000);
          console.info("push progress page success " + JSON.stringify(result));
        }
      } catch (err) {
        console.error("push progress page error: " + err);
      }
      done()
    });

    afterEach(async function () {
      await Utils.sleep(1000);
      console.info("progressScaleCount after each called");
    });

    /*
     * @tc.number       SUB_ACE_BASIC_ETS_API_0001
     * @tc.name         testprogressScaleCount0001
     * @tc.desic         aceprogressScaleCountEtsTest0001
     */
    it('testprogressScaleCount0001', 0, async function (done) {
      console.info('progressScaleCount testprogressScaleCount0001 START');
      await Utils.sleep(2000);
      let strJson = getInspectorByKey('progressStyleOptions');
      console.info("[testprogressScaleCount0001] component width strJson:" + strJson);
      let obj = JSON.parse(strJson);
      expect(obj.$type).assertEqual('Progress');
      expect(obj.$attrs.style.scaleCount).assertEqual("15");
      console.info("[testprogressScaleCount0001] style.scaleCount value :" + obj.$attrs.style.scaleCount);
      done();
    });

    /*
     * @tc.number       SUB_ACE_BASIC_ETS_API_0002
     * @tc.name         testprogressScaleCount0002
     * @tc.desic         aceprogressScaleCountEtsTest0002
     */
    it('testprogressScaleCount0002', 0, async function (done) {
      console.info('progressScaleCount testprogressScaleCount0002 START');
      await Utils.sleep(2000);
      let strJson = getInspectorByKey('progressStyleOptions');
      console.info("[testprogressScaleCount0002] component height strJson:" + strJson);
      let obj = JSON.parse(strJson);
      expect(obj.$type).assertEqual('Progress');
      expect(obj.$attrs.style.scaleWidth).assertEqual('5.00vp');
      console.info("[testprogressScaleCount0002] style.scaleWidth value :" + obj.$attrs.style.scaleWidth);
      done();
    });
  })
}
