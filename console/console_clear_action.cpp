#include "console_pane.h"
#include "console_clear_action.h"
#include "constants.h"
#include <dzapp.h>
#include <dzmainwindow.h>
#include <dzpanemgr.h>
#include <QtGui/qmessagebox.h>

ConsoleClearAction::ConsoleClearAction() 
  : DzAction("Clear", "Clear log file") 
{
  setObjectName("ConsoleClearAction");
}

void ConsoleClearAction::executeAction() {
  DzPane* pane = dzApp->getInterface()->getPaneMgr()->findPane("ConsolePane");

  if (pane == nullptr) {
    QMessageBox::warning(0, this->objectName(), QString(CONSOLE_ACTION_PANE_NOT_FOUND_MSG), QMessageBox::Ok);

    return;
  }

  ConsolePane* consolePane = dynamic_cast<ConsolePane*>(pane);
  consolePane->clearLog();
}

