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

#include "rs_constants.h"
#include "rs_pane.h"
#include "rs_setup_action.h"
#include <dzapp.h>
#include <dzmainwindow.h>
#include <dzpanemgr.h>
#include <QtGui/qmessagebox.h>

RenderStatisticsSetupAction::RenderStatisticsSetupAction() 
  : DzAction("Settings", "Setup render statistics") 
{
  setObjectName("SetupAction");
}

void RenderStatisticsSetupAction::executeAction() {
  DzPane* pane = dzApp->getInterface()->getPaneMgr()->findPane("RenderStatisticsPane");

  if (pane == nullptr) {
    QMessageBox::warning(0, this->objectName(), QString(RS_PANE_NOT_FOUND_MSG), QMessageBox::Ok);

    return;
  }

  RenderStatisticsPane* renderStatisticsPane = dynamic_cast<RenderStatisticsPane*>(pane);
  renderStatisticsPane->showSettingsDialog();
}
