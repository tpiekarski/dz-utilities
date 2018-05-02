#include "statistics-test.h"

void StatisticsTest::init() {
  statistics = new RenderStatistics("QtTest", 2);
}

void StatisticsTest::testStatistics() {
  // todo: test statistics layer
}

void StatisticsTest::cleanup() {
  delete(statistics);
  statistics = nullptr;
}
