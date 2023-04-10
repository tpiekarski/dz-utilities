/*
* Project:   dzUtilities::Console
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2023 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#include "console_flush_log_action.h"
#include "console_constants.h"
#include "console_pane.h"
#include <dzapp.h>
#include <dzmainwindow.h>
#include <dzpanemgr.h>
#include <QtGui/qmessagebox.h>

ConsoleFlushLogAction::ConsoleFlushLogAction()
  : DzAction("Flush", "Flush log buffer")
{
  setObjectName("ConsoleFlushLogAction");
}

void ConsoleFlushLogAction::executeAction() {
  dzApp->flushLogBuffer();
}
