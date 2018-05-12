#include "console_log_browser.h"
#include "constants.h"
#include <dzapp.h>

ConsoleLogBrowser::ConsoleLogBrowser(QWidget* parent, Console* console, ConsoleSettings* settings) {
  this->console = console;
  this->settings = settings;

  logWatched = false;
  logBrowser = new QTextBrowser(parent);
  logBrowser->setObjectName("LogBrowser");
  logBrowser->setMinimumSize(PANE_MIN_WIDTH, PANE_MIN_HEIGHT);

  float fontSize;
  settings->getFontSize(&fontSize);
  logBrowser->setFontPointSize(fontSize);

  logBrowserLayout = new QHBoxLayout(parent);
  logBrowserLayout->setObjectName("LogBrowserLayout");
  logBrowserLayout->addWidget(logBrowser);

  connect(dzApp, SIGNAL(starting()), this, SLOT(openLog()));
}


ConsoleLogBrowser::~ConsoleLogBrowser() {
  console->closeLog();

  if (logBrowser != nullptr) {
    delete(logBrowser);
    logBrowser = nullptr;
  }

  if (logBrowserLayout != nullptr) {
    delete(logBrowserLayout);
    logBrowserLayout = nullptr;
  }
}

void ConsoleLogBrowser::openLog() {
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

void ConsoleLogBrowser::updateLog() {
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

void ConsoleLogBrowser::reloadLog() {
  logBrowser->clear();
  console->resetLog();
  openLog();
}

void ConsoleLogBrowser::clearLog() {
  logBrowser->clear();
}

void ConsoleLogBrowser::moveCursor(const QTextCursor::MoveOperation position) {
  logBrowser->moveCursor(position, QTextCursor::MoveAnchor);
}