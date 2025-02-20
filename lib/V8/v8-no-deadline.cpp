////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2014-2024 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Business Source License 1.1 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     https://github.com/arangodb/arangodb/blob/devel/LICENSE
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Wilfried Goesgens
////////////////////////////////////////////////////////////////////////////////

#ifndef USE_V8
#error this file is not supposed to be used in builds with -DUSE_V8=Off
#endif

#include <optional>
#include "v8-deadline.h"

// arangod dummy implementation doing nothing
void setExecutionDeadlineInMS(uint64_t timeout) {}

bool isExecutionDeadlineReached() { return false; }
bool isExecutionDeadlineReached(v8::Isolate* isolate) { return false; }

double correctTimeoutToExecutionDeadlineS(double timeoutSeconds) {
  return timeoutSeconds;
}

std::chrono::milliseconds correctTimeoutToExecutionDeadline(
    std::chrono::milliseconds timeout) {
  return timeout;
}

uint32_t correctTimeoutToExecutionDeadline(uint32_t timeout) { return timeout; }

void TRI_InitV8Deadline(v8::Isolate* isolate, uint32_t timeout) {}
void triggerV8DeadlineNow(bool fromSignal) {}

namespace arangodb {
std::optional<ExternalProcessStatus> getHistoricStatus(
    TRI_pid_t pid, arangodb::application_features::ApplicationServer& server) {
  return std::nullopt;
}
}  // namespace arangodb
