// Render Statistics Headers
#include "clear_action.h"
#include "pane.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzmainwindow.h"
#include "dzpanemgr.h"

// Qt SDK Headers
#include "QtGui\qmessagebox.h"


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