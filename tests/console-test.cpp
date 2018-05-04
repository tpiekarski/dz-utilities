#include "console-test.h"

ConsoleTest::ConsoleTest(const QString logPath) {
  this->logPath = logPath;
}

void ConsoleTest::init() {
  console = new Console(NULL, logPath);
}

void ConsoleTest::cleanup() {
  delete(console);
  console = nullptr;
}

void ConsoleTest::testConsoleIsOpeningLog() {
  // todo: implement testConsoleIsOpeningLog
}

void ConsoleTest::testConsoleIsProvidingLog() {
  // todo: implement testConsoleIsProvidingLog
}

void ConsoleTest::testConsoleIsProvidingLogUpdates() {
  // todo: implement testConsoleIsProvidingLogUpdates
}

void ConsoleTest::testConsoleIsResetingLog() {
  // todo: implement testConsoleIsResetingLog
}

void ConsoleTest::testConsoleIsClosingLog() {
  // todo: implement testConsoleIsClosingLog
}
