#ifndef H_RENDERSTATISTICS_TEST
#define H_RENDERSTATISTICS_TEST

#include <QtTest/QtTest>
#include <statistics.h>

class StatisticsTest : public QObject {

  Q_OBJECT

public:
  StatisticsTest() = default;

private slots:
  void init();
  void cleanup();

  void testStatisticsAreCollectingBasicData();
  void testStatisticsAreCountingRenderings();
  void testStatisticsAreProvidingStartDate();
  void testStatisticsAreProvidingDurationInSeconds();
  void testStatisticsAreProvidingStartTime();
  void testStatisticsAreProvidingStringRepresentation();
  void testStatisticsAreStoppingClock();
  void testStatisticsAreMeasuringTime();

private:
  RenderStatistics* statistics;
};
#endif
