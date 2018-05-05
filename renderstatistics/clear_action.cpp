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

#include "clear_action.h"
#include "pane.h"
#include <dzapp.h>
#include <dzmainwindow.h>
#include <dzpanemgr.h>
#include <QtGui/qmessagebox.h>

RenderStatisticsClearAction::RenderStatisticsClearAction()
  : DzAction("Clear", "Clear render statistics") 
{
  setObjectName("ClearAction");
}

void RenderStatisticsClearAction::executeAction() {
  DzPane* pane = dzApp->getInterface()->getPaneMgr()->findPane("RenderStatisticsPane");

  if (pane == nullptr) {
    QMessageBox::warning(0, this->objectName(), QString("RenderStatisticsPane not found."), QMessageBox::Ok);
  }

  RenderStatisticsPane* statisticsPane = dynamic_cast<RenderStatisticsPane*>(pane);
  statisticsPane->clear();
}