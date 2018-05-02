#include "console-test.h"

ConsoleTest::ConsoleTest(const QString logPath) {
  this->logPath = logPath;
}

void ConsoleTest::init() {
  console = new Console(NULL, logPath);
}

void ConsoleTest::testConsole() {
  // todo: test console layer
}

void ConsoleTest::cleanup() {
  delete(console);
  console = nullptr;
}
