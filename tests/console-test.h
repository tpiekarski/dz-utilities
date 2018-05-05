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

#ifndef H_CONSOLE_TEST
#define H_CONSOLE_TEST

#include <console.h>
#include <QtTest/QtTest>

class ConsoleTest : public QObject {

  Q_OBJECT

public:
  ConsoleTest(const QString logPath);

  private slots:
  void init();
  void cleanup();

  void testConsoleIsOpeningLog();
  void testConsoleIsProvidingLog();
  void testConsoleIsProvidingLogUpdates();
  void testConsoleIsResetingLog();
  void testConsoleIsClosingLog();

private:
  Console* console;
  QString logPath;
};
#endif
