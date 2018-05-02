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