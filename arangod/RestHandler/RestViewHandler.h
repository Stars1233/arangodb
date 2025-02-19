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
/// @author Jan Steemann
/// @author Daniel H. Larkin
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "RestHandler/RestVocbaseBaseHandler.h"

namespace arangodb {

////////////////////////////////////////////////////////////////////////////////
/// @brief view request handler
////////////////////////////////////////////////////////////////////////////////

class RestViewHandler : public RestVocbaseBaseHandler {
 public:
  RestViewHandler(ArangodServer&, GeneralRequest*, GeneralResponse*);

 public:
  char const* name() const override final { return "RestViewHandler"; }
  RequestLane lane() const override final { return RequestLane::CLIENT_SLOW; }
  virtual RestStatus execute() override;

 protected:
  void createView();
  void modifyView(bool partialUpdate);
  void deleteView();
  void getView(std::string const& nameOrId, bool detailed);
  void getViews();
};

}  // namespace arangodb
