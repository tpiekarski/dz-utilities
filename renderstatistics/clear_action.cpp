// Render Statistics Headers
#include "clear_action.h"
#include "pane.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzmainwindow.h"
#include "dzpanemgr.h"

RenderStatisticsClearAction::RenderStatisticsClearAction()
  : DzAction("Clear", "Clear render statistics") 
{
  setObjectName("ClearAction");
}

void RenderStatisticsClearAction::executeAction() {
  DzMainWindow* mainWindow = dzApp->getInterface();
  DzPaneMgr* paneManager = mainWindow->getPaneMgr();
  DzPane* pane = paneManager->findPane("RenderStatisticsPane");

  RenderStatisticsPane* statisticsPane = dynamic_cast<RenderStatisticsPane*>(pane);

  statisticsPane->clear();
}