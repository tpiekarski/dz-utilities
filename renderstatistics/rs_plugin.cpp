/*
* Project:   dzUtilities::RenderStatistics
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#include "rs_clear_action.h"
#include "rs_guid.h"
#include "rs_pane.h"
#include "rs_pane_action.h"
#include "rs_setup_action.h"
#include "rs_version.h"
#include <dzapp.h>
#include <dzplugin.h>

DZ_PLUGIN_DEFINITION(PLUGIN_NAME)
DZ_PLUGIN_AUTHOR("Thomas Piekarski")
DZ_PLUGIN_VERSION(PLUGIN_MAJOR, PLUGIN_MINOR, PLUGIN_REV, PLUGIN_BUILD)
DZ_PLUGIN_DESCRIPTION(QString(
  "<strong>Render Statistics Plugin</strong>"
  "<p>"
  "%1. It tries to answer such questions like "
  "<em>how many renders did I started</em>, <em>how long did they took in average</em> "
  "and a few more such questions. Next to these questions it stores the rendered "
  "images which can be accessed, saved and browsed. The data is only stored in the "
  "current session and is not yet saved, so are the rendered images as well."
  "</p>"
  "<p><strong>The plugin is provided \"as is\", without warranty of any kind.</strong></p>"
  "<p>"
  "For more information, current development and updates please refer to the "
  "<a href=\"https://github.com/tpiekarski/dzUtilities\">project website</a> at Github."
  "</p>"
).arg(PLUGIN_TAGLINE));

DZ_PLUGIN_CLASS_GUID(RenderStatisticsPane, RENDERSTATISTICS_PANE_CLASS_GUID)
DZ_PLUGIN_CLASS_GUID(RenderStatisticsPaneAction, RENDERSTATISTICS_PANE_ACTION_CLASS_GUID)
DZ_PLUGIN_CLASS_GUID(RenderStatisticsClearAction, RENDERSTATISTICS_CLEAR_ACTION_CLASS_GUID)
DZ_PLUGIN_CLASS_GUID(RenderStatisticsSetupAction, RENDERSTATISTICS_SETUP_ACTION_CLASS_GUID)
