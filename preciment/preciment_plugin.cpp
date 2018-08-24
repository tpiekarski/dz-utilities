/*
* Project:   dzUtilities::Preciment
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#include "preciment_control_action.h"
#include "preciment_guid.h"
#include "preciment_version.h"
#include <dzplugin.h>

DZ_PLUGIN_DEFINITION(PLUGIN_NAME);
DZ_PLUGIN_AUTHOR("Thomas Piekarski");
DZ_PLUGIN_VERSION(PLUGIN_MAJOR, PLUGIN_MINOR, PLUGIN_REV, PLUGIN_BUILD);
DZ_PLUGIN_DESCRIPTION(QString(
  "<strong>Preciment Plugin</strong>"
  "<p>%1</p>"
  "<p><strong>The plugin is provided \"as is\", without warranty of any kind.</strong></p>"
  "<p>"
  "For more information, current development and updates please refer to the "
  "<a href=\"https://github.com/tpiekarski/dzUtilities\">project website</a> at Github."
  "</p>"
).arg(PLUGIN_TAGLINE));

DZ_PLUGIN_CLASS_GUID(PrecimentControlAction, PRECIMENT_CONTROL_ACTION_GUID);