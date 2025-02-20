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
/// @author Manuel Pöter
////////////////////////////////////////////////////////////////////////////////

#include "LogContext.h"

#include <vector>

using namespace arangodb;

thread_local LogContext::ThreadControlBlock LogContext::_threadControlBlock;

void LogContext::clear(EntryCache& cache) {
  if (_tail) {
    if (_tail->decRefCnt() == 1) {
      _tail->release(cache);
    }
    _tail = nullptr;
  }
}

LogContext::ScopedContext::ScopedContext(LogContext ctx) noexcept {
  auto& local = LogContext::controlBlock();
  _oldContext = std::move(local._logContext);
  local._logContext = std::move(ctx);
}

LogContext::ScopedContext::ScopedContext(
    LogContext ctx, LogContext::ScopedContext::DontRestoreOldContext) noexcept {
  auto& local = LogContext::controlBlock();
  local._logContext.clear(local._entryCache);
  local._logContext = std::move(ctx);
}

LogContext::ScopedContext::~ScopedContext() {
  auto& local = LogContext::controlBlock();
  local._logContext.clear(local._entryCache);
  if (_oldContext) {
    local._logContext = std::move(_oldContext).value();
  }
}

void LogContext::visit(Visitor const& visitor) const {
  doVisit(visitor, _tail);
}

void LogContext::doVisit(Visitor const& visitor, Entry const* entry) const {
  if (entry != nullptr) {
    doVisit(visitor, entry->_prev);
    entry->visit(visitor);
  }
}

void LogContext::setCurrent(LogContext ctx) noexcept {
  _threadControlBlock._logContext = std::move(ctx);
}
