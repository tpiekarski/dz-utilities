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

#include "console_constants.h"
#include "console_pane.h"
#include "console_settings_action.h"
#include <dzapp.h>
#include <dzmainwindow.h>
#include <dzpanemgr.h>
#include <QtGui/qmessagebox.h>

ConsoleSettingsAction::ConsoleSettingsAction() 
  : DzAction("Settings", "Console Settings") 
{
  setObjectName("ConsoleSettingsAction");
}

void ConsoleSettingsAction::executeAction() {
  DzPane* pane = dzApp->getInterface()->getPaneMgr()->findPane("ConsolePane");

  if (pane == nullptr) {
    QMessageBox::warning(0, this->objectName(), QString(CONSOLE_ACTION_PANE_NOT_FOUND_MSG), QMessageBox::Ok);

    return;
  }

  ConsolePane* consolePane = dynamic_cast<ConsolePane*>(pane);
  consolePane->showSettingsDialog();
}

