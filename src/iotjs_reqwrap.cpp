/* Copyright 2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "iotjs_def.h"
#include "iotjs_reqwrap.h"


namespace iotjs {


ReqWrap::ReqWrap(JObject& jcallback, uv_req_t* req)
    : __req(req)
    , _jcallback(NULL) {
  if (!jcallback.IsNull()) {
    _jcallback = new JObject(jcallback);
  }
}


ReqWrap::~ReqWrap() {
  if (_jcallback != NULL) {
    delete _jcallback;
  }
}


JObject& ReqWrap::jcallback() {
  IOTJS_ASSERT(_jcallback != NULL);
  return *_jcallback;
}


uv_req_t* ReqWrap::req() {
  return __req;
}


void ReqWrap::Dispatched() {
  req()->data = this;
}


} // namespace iotjs
