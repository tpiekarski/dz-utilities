// Console Headers
#include "consolepane.h"
#include "console_properties_action.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzmainwindow.h"
#include "dzpanemgr.h"

ConsolePropertiesAction::ConsolePropertiesAction() 
  : DzAction("Properties", "Properties log file") 
{
  setObjectName("ConsolePropertiesAction");
}

void ConsolePropertiesAction::executeAction() {
  DzPane* pane = dzApp->getInterface()->getPaneMgr()->findPane("ConsolePane");
  ConsolePane* consolePane = dynamic_cast<ConsolePane*>(pane);

  consolePane->showProperties();
}

