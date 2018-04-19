// Console Headers
#include "consolepane.h"
#include "console_reload_action.h"
#include "constants.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzmainwindow.h"
#include "dzpanemgr.h"

// Qt SDK Headers
#include "QtGui\qmessagebox.h"

ConsoleReloadAction::ConsoleReloadAction() 
  : DzAction("Reload", "Reload log file") 
{
  setObjectName("ConsoleReloadAction");
}

void ConsoleReloadAction::executeAction() {
  DzPane* pane = dzApp->getInterface()->getPaneMgr()->findPane("ConsolePane");

  if (pane == nullptr) {
    QMessageBox::warning(0, this->objectName(), QString(CONSOLE_ACTION_PANE_NOT_FOUND_MSG), QMessageBox::Ok);

    return;
  }

  ConsolePane* consolePane = dynamic_cast<ConsolePane*>(pane);
  consolePane->reloadLog();
}

