// Console Headers
#include "consolepane.h"
#include "console_reload_action.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzmainwindow.h"
#include "dzpanemgr.h"

ConsoleReloadAction::ConsoleReloadAction() 
  : DzAction("Reload", "Reload log file") 
{
  setObjectName("ConsoleReloadAction");
}

void ConsoleReloadAction::executeAction() {
  DzPane* pane = dzApp->getInterface()->getPaneMgr()->findPane("ConsolePane");
  ConsolePane* consolePane = dynamic_cast<ConsolePane*>(pane);

  consolePane->reloadLog();
}

