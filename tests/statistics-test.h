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

#ifndef H_RENDERSTATISTICS_TEST
#define H_RENDERSTATISTICS_TEST

#include <QtTest/QtTest>
#include <rs_statistics.h>

class StatisticsTest : public QObject {

  Q_OBJECT

public:
  StatisticsTest();

private slots:
  void init();
  void cleanup();

  void testStatisticsAreCollectingBasicData();
  void testStatisticsAreMeasuringTime();
  void testStatisticsAreFormatingStartDate();
  void testStatisticsAreProvidingStartDateMultipleTimes();
  void testStatisticsAreFormatingStartTime();
  void testStatisticsAreProvidingStartTimeMultipleTimes();
  void testStatisticsAreProvidingDurationInSeconds();
  
  void testStatisticsAreProvidingStringRepresentation();

private:
  RenderStatistics* statistics;
};
#endif
