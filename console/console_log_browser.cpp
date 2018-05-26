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
#include "console_log_browser.h"
#include <dzapp.h>

ConsoleLogBrowser::ConsoleLogBrowser(Console* console, ConsoleSettings* settings) {
  this->console = console;
  this->settings = settings;

  logWatched = false;
  browser = new QTextEdit();
  browser->setObjectName("LogBrowser");
  browser->setMinimumSize(CONSOLE_PANE_MIN_WIDTH, CONSOLE_PANE_MIN_HEIGHT);
  browser->setReadOnly(true);

  float fontSize;
  settings->getFontSize(&fontSize);
  browser->setFontPointSize(fontSize);

  QTextCursor textCursor(browser->document());
  currentCharacterFormat = new QTextCharFormat(textCursor.charFormat());
  currentCharacterFormat->setFontPointSize(fontSize);

  layout = new QHBoxLayout();
  layout->setObjectName("LogBrowserLayout");
  layout->addWidget(browser);

  connect(dzApp, SIGNAL(starting()), this, SLOT(openLog()));
}

ConsoleLogBrowser::~ConsoleLogBrowser() {
  console->closeLog();

  if (browser != nullptr) {
    delete browser ;
    browser = nullptr;
  }

  if (currentCharacterFormat != nullptr) {
    delete currentCharacterFormat;
    currentCharacterFormat = nullptr;
  }

  if (layout != nullptr) {
    delete layout;
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
      resetCharacterFormat();
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
  resetCharacterFormat();
  console->resetLog();
  openLog();

  emit logReloaded();
}

bool ConsoleLogBrowser::find(const QString searchTerm, const QTextDocument::FindFlags options) {
  return browser->find(searchTerm, options);
}

void ConsoleLogBrowser::clearLog() {
  browser->clear();
  resetCharacterFormat();

  emit logCleared();
}

void ConsoleLogBrowser::moveCursor(const QTextCursor::MoveOperation position) {
  browser->moveCursor(position, QTextCursor::MoveAnchor);
}

void ConsoleLogBrowser::updateFontSize(const QString newFontSize) {
  settings->setFontSize(newFontSize);
  float fontSize;
  settings->getFontSize(&fontSize);
  currentCharacterFormat->setFontPointSize(fontSize);
  browser->setFontPointSize(fontSize);
  reloadLog();
}

void ConsoleLogBrowser::resetCharacterFormat() {
  browser->textCursor().setCharFormat(*currentCharacterFormat);
}
