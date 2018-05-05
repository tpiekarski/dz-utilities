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

#include "console-test.h"
#include "statistics-test.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) { 
  if (argc != 2) {
    cout << "No path to a test log fixture provided, aborting.";

    return 1;
  }

  QCoreApplication app(argc, argv);
  const QString logPath = QString::fromAscii(argv[1]);

  ConsoleTest consoleTest(logPath);
  StatisticsTest statisticsTest;

  const int consoleTestResult = QTest::qExec(&consoleTest);
  const int statisticsTestResult = QTest::qExec(&statisticsTest);

  return (consoleTestResult == 0 && statisticsTestResult == 0) ? 0 : 1;
}