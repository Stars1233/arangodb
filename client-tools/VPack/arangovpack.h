////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2014-2022 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
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
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ApplicationFeatures/ApplicationFeature.h"
#include "Utils/ArangoClient.h"

namespace arangodb {

class VPackFeature;

using namespace application_features;

using ArangoVPackFeaturesList =
    TypeList<BasicFeaturePhaseClient, GreetingsFeaturePhase, VersionFeature,
             ConfigFeature, LoggerFeature, OptionsCheckFeature,
             FileSystemFeature, RandomFeature, ShellColorsFeature,
             ShutdownFeature, VPackFeature>;
struct ArangoVPackFeatures : ArangoVPackFeaturesList {};
using ArangoVPackServer = ApplicationServerT<ArangoVPackFeatures>;
using ArangoVPackFeature = ApplicationFeatureT<ArangoVPackServer>;

}  // namespace arangodb
