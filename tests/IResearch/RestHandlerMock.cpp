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
/// @author Andrey Abramov
/// @author Vasiliy Nabatchikov
////////////////////////////////////////////////////////////////////////////////

#include "RestHandlerMock.h"
#include "RestServer/VocbaseContext.h"
#include "VocBase/vocbase.h"

GeneralRequestMock::GeneralRequestMock(TRI_vocbase_t& vocbase)
    : arangodb::GeneralRequest(arangodb::ConnectionInfo{}, 1) {
  _authenticated = false;  // must be set before VocbaseContext::create(...)
  _context = arangodb::VocbaseContext::create(*this, vocbase);
  _context->vocbase().forceUse();  // must be called or ~VocbaseContext() will
                                   // fail at '_vocbase.release()'
  _requestContext =
      _context;  // do not use setRequestContext(...) since '_requestContext'
                 // has not been initialized and contains garbage
}
GeneralRequestMock::~GeneralRequestMock() = default;

size_t GeneralRequestMock::contentLength() const noexcept {
  return _contentLength;
}

std::string_view GeneralRequestMock::rawPayload() const {
  return std::string_view(reinterpret_cast<char const*>(_payload.data()),
                          _payload.size());
}

arangodb::velocypack::Slice GeneralRequestMock::payload(
    bool /*strictValidation*/) {
  return _payload.slice();
}

void GeneralRequestMock::setPayload(
    arangodb::velocypack::Buffer<uint8_t> buffer) {
  _payload.clear();
}

void GeneralRequestMock::setData(VPackSlice slice) {
  _payload.clear();
  _payload.add(slice);
}

GeneralResponseMock::GeneralResponseMock(
    arangodb::ResponseCode code /*= arangodb::ResponseCode::OK*/
    )
    : arangodb::GeneralResponse(code, 1) {}

void GeneralResponseMock::addPayload(
    arangodb::velocypack::Buffer<uint8_t>&& buffer,
    arangodb::velocypack::Options const* options /*= nullptr*/,
    bool resolveExternals /*= true*/
) {
  addPayload(arangodb::velocypack::Builder(buffer).slice(), options,
             resolveExternals);
}

void GeneralResponseMock::addPayload(
    arangodb::velocypack::Slice slice,
    arangodb::velocypack::Options const* options /*= nullptr*/,
    bool resolveExternals /*= true*/
) {
  _payload = options ? arangodb::velocypack::Builder(slice, options)
                     : arangodb::velocypack::Builder(slice);
}

void GeneralResponseMock::addRawPayload(std::string_view payload) {
  TRI_ASSERT(false);
}

void GeneralResponseMock::reset(arangodb::ResponseCode code) {
  _headers.clear();
  _payload.clear();
  _responseCode = code;
}

ErrorCode GeneralResponseMock::zlibDeflate(bool /*onlyIfSmaller*/) {
  // we should never get here
  TRI_ASSERT(false);
  return TRI_ERROR_INTERNAL;
}

ErrorCode GeneralResponseMock::gzipCompress(bool /*onlyIfSmaller*/) {
  // we should never get here
  TRI_ASSERT(false);
  return TRI_ERROR_INTERNAL;
}

ErrorCode GeneralResponseMock::lz4Compress(bool /*onlyIfSmaller*/) {
  // we should never get here
  TRI_ASSERT(false);
  return TRI_ERROR_INTERNAL;
}

// -----------------------------------------------------------------------------
// --SECTION--                                                       END-OF-FILE
// -----------------------------------------------------------------------------
