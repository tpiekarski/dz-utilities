#include "statistics-test.h"

void StatisticsTest::init() {
  statistics = new RenderStatistics("QtTest", 2);
}

void StatisticsTest::cleanup() {
  delete(statistics);
  statistics = nullptr;
}

void StatisticsTest::testStatisticsAreCollectingBasicData() {
  // todo: implement testStatisticsAreCollectingBasicData
}

void StatisticsTest::testStatisticsAreCountingRenderings() {
  // todo: implement testStatisticsAreCountingRenderings
}

void StatisticsTest::testStatisticsAreProvidingStartDate() {
  // todo: implement testStatisticsAreProvidingStartDate
}

void StatisticsTest::testStatisticsAreProvidingDurationInSeconds() {
  // todo: implement testStatisticsAreProvidingDurationInSeconds
}

void StatisticsTest::testStatisticsAreProvidingStartTime() {
  // todo: implement testStatisticsAreProvidingStartTime
}

void StatisticsTest::testStatisticsAreProvidingStringRepresentation() {
  // todo: implement testStatisticsAreProvidingStringRepresentation
}

void StatisticsTest::testStatisticsAreStoppingClock() {
  // todo: implement testStatisticsAreStoppingClock
}

void StatisticsTest::testStatisticsAreMeasuringTime() {
  // todo: implement testStatisticsAreMeasuringTime
}
