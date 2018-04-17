// Console Headers
#include "consolepane.h"
#include "console_clear_action.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzmainwindow.h"
#include "dzpanemgr.h"

ConsoleClearAction::ConsoleClearAction() 
  : DzAction("Clear", "Clear log file") 
{
  setObjectName("ConsoleClearAction");
}

void ConsoleClearAction::executeAction() {
  DzPane* pane = dzApp->getInterface()->getPaneMgr()->findPane("ConsolePane");
  ConsolePane* consolePane = dynamic_cast<ConsolePane*>(pane);

  consolePane->clearLog();
}

