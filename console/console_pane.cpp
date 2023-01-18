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

#include "console_constants.h"
#include "console_pane.h"
#include "console_settings_dialog.h"
#include "console_settings.h"
#include <dzapp.h>
#include <dzmainwindow.h>
#include <dzstyle.h>
#include <QtCore/qstring.h>
#include <QtGui/qmessagebox.h>

ConsolePane::ConsolePane() : DzPane("Console") {
  QString appDataInstancePath = dzApp->getAppDataPath();
  QMetaObject::invokeMethod(dzApp, "getAppDataInstancePath", Qt::DirectConnection, Q_RETURN_ARG(QString, appDataInstancePath));

  console = new Console(this, appDataInstancePath);
  consoleSettings = new ConsoleSettings(console->getLogFullPath());
  consoleLogBrowser = new ConsoleLogBrowser(console, consoleSettings);
  consoleSearchPane = new ConsoleSearchPane(consoleLogBrowser);

  paneMainLayout = new QVBoxLayout();
  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  paneMainLayout->setMargin(margin);
  paneMainLayout->setSpacing(margin);
  setLayout(paneMainLayout);
  setMinimumSize(CONSOLE_PANE_MIN_WIDTH, CONSOLE_PANE_MIN_HEIGHT);

  paneMainLayout->addLayout(consoleSearchPane->getLayout());
  paneMainLayout->addLayout(consoleLogBrowser->getLayout());
}

ConsolePane::~ConsolePane() {
  if (consoleSearchPane != nullptr) {
    delete consoleSearchPane;
    consoleSearchPane = nullptr;
  }

  if (consoleLogBrowser != nullptr) {
    delete consoleLogBrowser;
    consoleLogBrowser = nullptr;
  }

  if (consoleSettings != nullptr) {
    delete consoleSettings;
    consoleSettings = nullptr;
  }

  if (console != nullptr) {
    delete console;
    console = nullptr;
  }

  if (paneMainLayout != nullptr) {
    delete paneMainLayout;
    paneMainLayout = nullptr;
  }

}

void ConsolePane::showSettingsDialog() {
  DzMainWindow* mainWindow = dzApp->getInterface();
  if (mainWindow == nullptr) {
    QMessageBox::warning(0, "Error", "The main window is not available.", QMessageBox::Ok);

    return;
  }

  ConsoleSettingsDialog* dialog = new ConsoleSettingsDialog(mainWindow, consoleSettings);
  if (dialog == nullptr) {
    QMessageBox::warning(0,"Error","The dialog for console settings could not be created.", QMessageBox::Ok);

    return;
  }

  if (dialog->exec() == 1) {
    const QString newFontSize = dialog->getNewFontSize();
    QString previousFontSize = NULL;
    consoleSettings->getFontSize(&previousFontSize);
    if (previousFontSize != newFontSize && consoleSettings->validateFontSize(newFontSize)) {
      consoleLogBrowser->updateFontSize(newFontSize);
    }

    const QColor newHighlightColor = dialog->getNewHighlightColor();
    if (newHighlightColor != consoleSettings->getHighlightColor()) {
      consoleSettings->setHighlightColor(newHighlightColor);
    }

  }

  if (dialog != nullptr) {
    delete dialog;
    dialog = nullptr;
  }

}

void ConsolePane::buildOptionsMenu(DzActionMenu* menu) const {
  menu->insertAction("ConsoleClearAction");
  menu->insertAction("ConsoleReloadAction");
  menu->insertAction("ConsoleSettingsAction");
}
