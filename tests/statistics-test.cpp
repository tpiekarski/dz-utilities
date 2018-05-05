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

#include "statistics-test-constants.h"
#include "statistics-test-macros.h"
#include "statistics-test.h"

StatisticsTest::StatisticsTest() {
  statistics = nullptr;
}

void StatisticsTest::init() {
  statistics = new RenderStatistics(TEST_ENGINE, TEST_NODES);
}

void StatisticsTest::cleanup() {
  if (!statistics->isFinished()) {
    statistics->stopClock();
  }

  if (statistics != nullptr) {
    delete(statistics);
    statistics = nullptr;
  }
}

void StatisticsTest::testStatisticsAreCollectingBasicData() {
  QCOMPARE(QString::fromStdString(statistics->getEngine()), QString(TEST_ENGINE));
  QCOMPARE(statistics->getNodes(), TEST_NODES);
  QVERIFY(!statistics->isFinished());
  QVERIFY(!statistics->isSucceeded());
}

void StatisticsTest::testStatisticsAreMeasuringTime() {
  QTest::qSleep(TEST_SLEEP_MILLISECONDS);
  statistics->stopClock();
  const double sleep = STATISTICS_GET_SLEEP_SECONDS();
  const double time = statistics->getRenderingDuration().count();

  QVERIFY(time > 0.0);
  QVERIFY(time >= sleep);
  QVERIFY(time <= sleep + TEST_TIME_MEASURING_OFFSET);
  QVERIFY(statistics->isFinished());
}

void StatisticsTest::testStatisticsAreProvidingStartDate() {
  date_facet* dateFacet = new date_facet();
  dateFacet->format(DATE_FACET_FORMAT);
  STATISTICS_BUILD_CURRENT_DATETIME(now, dateFacet);

  QCOMPARE(QString::fromStdString(statistics->getStartDate()), now);
}

void StatisticsTest::testStatisticsAreProvidingStartTime() {
  time_facet* timeFacet = new time_facet();
  timeFacet->format(TIME_FACET_FORMAT);
   
  STATISTICS_BUILD_CURRENT_DATETIME(now, timeFacet);

  QCOMPARE(QString::fromStdString(statistics->getStartTime()), now);
}

void StatisticsTest::testStatisticsAreProvidingDurationInSeconds() {
  STATISTICS_STOP_CLOCK(TEST_SLEEP_MILLISECONDS);

  QCOMPARE(
    QString::fromStdString(statistics->getDurationInSeconds()), 
    QString::number(STATISTICS_GET_SLEEP_SECONDS())
  );
}

void StatisticsTest::testStatisticsAreProvidingStringRepresentation() {
  STATISTICS_STOP_CLOCK(TEST_SLEEP_MILLISECONDS);
  const QString expectedString = STATISTICS_GET_STRING_REPRESENTATION();

  QCOMPARE(QString::fromStdString(statistics->toString()), expectedString);
}
