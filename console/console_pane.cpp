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
#include <QtCore/qfile.h>
#include <QtCore/qobject.h>
#include <QtCore/qstring.h>
#include <QtGui/qboxlayout.h>
#include <QtGui/qmessagebox.h>
#include <QtGui/qtextbrowser.h>
#include <dzapp.h>
#include <dzmainwindow.h>
#include <dzstyle.h>

ConsolePane::ConsolePane() : DzPane("Console") {
  console = new Console(this, dzApp->getAppDataPath());
  settings = new ConsoleSettings();
  settings->setLogFilePath(console->getLogFullPath());

  QVBoxLayout* paneMainLayout = new QVBoxLayout();
  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  paneMainLayout->setMargin(margin);
  paneMainLayout->setSpacing(margin);
  setLayout(paneMainLayout);
  setMinimumSize(PANE_MIN_WIDTH, PANE_MIN_HEIGHT);

  logWatched = false;
  logBrowser = new QTextBrowser();
  logBrowser->setObjectName("Console");
  logBrowser->setMinimumSize(PANE_MIN_WIDTH, PANE_MIN_HEIGHT);

  float fontSize;
  settings->getFontSize(&fontSize);
  logBrowser->setFontPointSize(fontSize);

  paneMainLayout->addWidget(logBrowser);
  connect(dzApp, SIGNAL(starting()), this, SLOT(openLog()));
}

ConsolePane::~ConsolePane() {
  console->closeLog();

  if (settings != nullptr) {
    delete(settings);
    settings = nullptr;
  }

  if (console != nullptr) {
    delete(console);
    console = nullptr;
  }

}

void ConsolePane::openLog() {
  if (!console->openLog()) {
    logBrowser->setPlainText(QString("The log file %s could not be opened.").arg(console->getLogFullPath()));

    return;
  }

  logBrowser->setPlainText(console->getLog());
  moveCursor(QTextCursor::End);
  
  if (!logWatched) {
    logWatched = connect(console->getLogWatcher(), SIGNAL(fileChanged(const QString&)), this, SLOT(updateLog()));
  }
}

void ConsolePane::updateLog() {
  if (console->isLogOpen()) {
    QString logUpdates = console->getLogUpdates();
    if (logUpdates != nullptr && logUpdates.length() > 1) {
      logBrowser->append(logUpdates);
      moveCursor(QTextCursor::End);
    }
  }
  else {
    logBrowser->append(QString("The log file %1 is not open anymore.").arg(console->getLogFullPath()));
  }
}

void ConsolePane::reloadLog() {
  logBrowser->clear();
  console->resetLog();
  openLog();
}

void ConsolePane::clearLog() {
  logBrowser->clear();
}

void ConsolePane::showProperties() {
  DzMainWindow* mainWindow = dzApp->getInterface();
  if (mainWindow == nullptr) {
    QMessageBox::warning(0, "Error", "The main window is not available.", QMessageBox::Ok);

    return;
  }

  ConsolePropertiesDialog* dialog = new ConsolePropertiesDialog(mainWindow, settings);
  if (dialog == nullptr) {
    QMessageBox::warning(0,"Error","The dialog for console settings could not be created.", QMessageBox::Ok);

    return;
  }

  const int dialogResult = dialog->exec();
  const QString newFontSize = dialog->getNewFontSize();

  QString previousFontSize = NULL;
  settings->getFontSize(&previousFontSize);

  if (dialogResult == 1 && previousFontSize != newFontSize && settings->validateFontSize(newFontSize)) {
    settings->setFontSize(dialog->getNewFontSize());

    float fontSize;
    settings->getFontSize(&fontSize);

    logBrowser->setFontPointSize(fontSize);
    reloadLog();
  }

}

void ConsolePane::buildOptionsMenu(DzActionMenu* menu) const {
  menu->insertAction("ConsoleClearAction");
  menu->insertAction("ConsoleReloadAction");
  menu->insertAction("ConsolePropertiesAction");
}

void ConsolePane::moveCursor(const QTextCursor::MoveOperation position) {
  logBrowser->moveCursor(position, QTextCursor::MoveAnchor);
}
