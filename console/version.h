/*
* Project:   dzUtilities::Console
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#ifndef H_CONSOLE_VERSION
#define H_CONSOLE_VERSION

#include <dzversion.h>

/*
 * Version Definition
 */
#define PLUGIN_MAJOR 1
#define PLUGIN_MINOR 0
#define PLUGIN_REV 0
#define PLUGIN_BUILD 1

#define PLUGIN_VERSION DZ_MAKE_VERSION( \
  PLUGIN_MAJOR, PLUGIN_MINOR, PLUGIN_REV, PLUGIN_BUILD \
)

#endif
