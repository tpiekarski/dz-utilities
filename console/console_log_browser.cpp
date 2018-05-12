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

#include "console_log_browser.h"
#include "constants.h"
#include <dzapp.h>

ConsoleLogBrowser::ConsoleLogBrowser(Console* console, ConsoleSettings* settings) {
  this->console = console;
  this->settings = settings;

  logWatched = false;
  browser = new QTextBrowser();
  browser->setObjectName("LogBrowser");
  browser->setMinimumSize(PANE_MIN_WIDTH, PANE_MIN_HEIGHT);

  float fontSize;
  settings->getFontSize(&fontSize);
  browser->setFontPointSize(fontSize);

  layout = new QHBoxLayout();
  layout->setObjectName("LogBrowserLayout");
  layout->addWidget(browser);

  connect(dzApp, SIGNAL(starting()), this, SLOT(openLog()));
}


ConsoleLogBrowser::~ConsoleLogBrowser() {
  console->closeLog();

  if (browser != nullptr) {
    delete(browser);
    browser = nullptr;
  }

  if (layout != nullptr) {
    delete(layout);
    layout = nullptr;
  }
}

void ConsoleLogBrowser::openLog() {
  if (!console->openLog()) {
    browser->setPlainText(QString("The log file %s could not be opened.").arg(console->getLogFullPath()));

    return;
  }

  browser->setPlainText(console->getLog());
  moveCursor(QTextCursor::End);

  if (!logWatched) {
    logWatched = connect(console->getLogWatcher(), SIGNAL(fileChanged(const QString&)), this, SLOT(updateLog()));
  }
}

void ConsoleLogBrowser::updateLog() {
  if (console->isLogOpen()) {
    QString logUpdates = console->getLogUpdates();
    if (logUpdates != nullptr && logUpdates.length() > 1) {
      browser->append(logUpdates);
      moveCursor(QTextCursor::End);
    }
  }
  else {
    browser->append(QString("The log file %1 is not open anymore.").arg(console->getLogFullPath()));
  }
}

void ConsoleLogBrowser::reloadLog() {
  browser->clear();
  console->resetLog();
  openLog();
}

void ConsoleLogBrowser::clearLog() {
  browser->clear();
}

void ConsoleLogBrowser::moveCursor(const QTextCursor::MoveOperation position) {
  browser->moveCursor(position, QTextCursor::MoveAnchor);
}