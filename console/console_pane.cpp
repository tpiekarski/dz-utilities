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

#include "console_pane.h"
#include "console_properties_dialog.h"
#include "console_settings.h"
#include "constants.h"
#include <dzapp.h>
#include <dzmainwindow.h>
#include <dzstyle.h>
#include <QtCore/qstring.h>
#include <QtGui/qmessagebox.h>

ConsolePane::ConsolePane() : DzPane("Console") {
  console = new Console(this, dzApp->getAppDataPath());
  consoleSettings = new ConsoleSettings(console->getLogFullPath());
  consoleLogBrowser = new ConsoleLogBrowser(this, console, consoleSettings);

  paneMainLayout = new QVBoxLayout();
  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  paneMainLayout->setMargin(margin);
  paneMainLayout->setSpacing(margin);
  setLayout(paneMainLayout);
  setMinimumSize(PANE_MIN_WIDTH, PANE_MIN_HEIGHT);

  paneMainLayout->addLayout(consoleLogBrowser->getLayout());
}

ConsolePane::~ConsolePane() {
  if (consoleLogBrowser != nullptr) {
    delete(consoleLogBrowser);
    consoleLogBrowser = nullptr;
  }

  if (consoleSettings != nullptr) {
    delete(consoleSettings);
    consoleSettings = nullptr;
  }

  if (console != nullptr) {
    delete(console);
    console = nullptr;
  }

}

void ConsolePane::showProperties() {
  DzMainWindow* mainWindow = dzApp->getInterface();
  if (mainWindow == nullptr) {
    QMessageBox::warning(0, "Error", "The main window is not available.", QMessageBox::Ok);

    return;
  }

  ConsolePropertiesDialog* dialog = new ConsolePropertiesDialog(mainWindow, consoleSettings);
  if (dialog == nullptr) {
    QMessageBox::warning(0,"Error","The dialog for console settings could not be created.", QMessageBox::Ok);

    return;
  }

  const int dialogResult = dialog->exec();
  const QString newFontSize = dialog->getNewFontSize();

  QString previousFontSize = NULL;
  consoleSettings->getFontSize(&previousFontSize);

  if (dialogResult == 1 && previousFontSize != newFontSize && consoleSettings->validateFontSize(newFontSize)) {
    consoleSettings->setFontSize(dialog->getNewFontSize());

    float fontSize;
    consoleSettings->getFontSize(&fontSize);

    consoleLogBrowser->getBrowser()->setFontPointSize(fontSize);
    consoleLogBrowser->reloadLog();
  }

}

void ConsolePane::buildOptionsMenu(DzActionMenu* menu) const {
  menu->insertAction("ConsoleClearAction");
  menu->insertAction("ConsoleReloadAction");
  menu->insertAction("ConsolePropertiesAction");
}
