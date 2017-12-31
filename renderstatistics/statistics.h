#ifndef H_RENDERSTATISTICS
#define H_RENDERSTATISTICS

#include<chrono>

// Qt SDK Headers
#include "QtCore\qstring.h"


using namespace std::chrono;

/*
 * Class: RenderStatistics
 * Description: Data class for keeping track of render statistics.
 */
class RenderStatistics {

public:
  RenderStatistics(QString engine, int nodes);
  ~RenderStatistics();

  void setCounter(int counter);
  void stopClock();
  QString getDurationInSeconds();
  QString toString();
  QString toRow();

private:
  QString engine;
  int nodes;
  int counter;
  bool finished;
  high_resolution_clock::time_point startTime;
  high_resolution_clock::time_point endTime;
  duration<double> renderingDuration;

  duration<double> calculateDuration();
};

#endif
