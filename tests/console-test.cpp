/*
* Project:   dzUtilities::Tests
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#include "console_constants.h"
#include "console-test.h"
#include "console-test-constants.h"
#include "console-test-macros.h"
#include <QtCore/QFile>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QTextStream>

ConsoleTest::ConsoleTest(const QString logPath) {
  console = nullptr;
  this->logPath = logPath;
}

void ConsoleTest::init() {
  console = new Console(NULL, logPath);
  TESTLOG_WRITE(QString(INITIAL_LOG_CONTENT).arg(CONSOLE_END_OF_LINE), QFile::WriteOnly);
}

void ConsoleTest::cleanup() {
  if (console != nullptr) {
    delete console;
    console = nullptr;
  }
}

void ConsoleTest::testConsoleIsOpeningLog() {
  QVERIFY(console->openLog());
  QVERIFY(console->isLogOpen());
}

void ConsoleTest::testConsoleIsProvidingLog() {
  TESTLOG_OPEN();
  const QString expectedString = QString(INITIAL_LOG_CONTENT).arg(CONSOLE_END_OF_LINE);
  const QString logContent = console->getLog();
  TESTLOG_CLOSE();

  QVERIFY(!logContent.isEmpty());
  QVERIFY(logContent.size() == 51);
  QCOMPARE(logContent, expectedString);
}

void ConsoleTest::testConsoleIsProvidingLogUpdates() {
  TESTLOG_OPEN();
  console->getLog();
  QString expectedString = UPDATED_LOG_CONTENT;

  TESTLOG_WRITE(expectedString, QFile::Append);
  expectedString.append(CONSOLE_END_OF_LINE);
  const QString updatedLogContent = console->getLogUpdates();
  TESTLOG_CLOSE();

  QVERIFY(!updatedLogContent.isEmpty());
  QVERIFY(updatedLogContent.size() == 55);
  QCOMPARE(updatedLogContent, expectedString);
}

void ConsoleTest::testConsoleIsResetingLog() {
  TESTLOG_OPEN();
  QMap<QString, QString> logContent;
  logContent.insert("beforeReset-1stCall", console->getLog().trimmed());
  logContent.insert("beforeReset-2ndCall", console->getLog().trimmed());
  console->resetLog();
  logContent.insert("afterReset", console->getLog().trimmed());
  TESTLOG_CLOSE();

  QVERIFY(logContent.value("beforeReset-2ndCall").isEmpty());
  QCOMPARE(logContent.value("afterReset"), logContent.value("beforeReset-1stCall"));
}

void ConsoleTest::testConsoleIsClosingLog() {
  TESTLOG_OPEN();
  console->closeLog();

  QVERIFY(!console->isLogOpen());
}
