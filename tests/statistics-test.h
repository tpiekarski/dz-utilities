#ifndef H_RENDERSTATISTICS_TEST
#define H_RENDERSTATISTICS_TEST

#include <QtTest/QtTest>
#include <statistics.h>

class StatisticsTest : public QObject {

  Q_OBJECT

public:
  StatisticsTest();

private slots:
  void init();
  void cleanup();

  void testStatisticsAreCollectingBasicData();
  void testStatisticsAreMeasuringTime();
  void testStatisticsAreProvidingStartDate();
  void testStatisticsAreProvidingStartTime();
  void testStatisticsAreProvidingDurationInSeconds();
  void testStatisticsAreProvidingStringRepresentation();

private:
  RenderStatistics* statistics;
};
#endif
