#ifndef H_RENDERSTATISTICS
#define H_RENDERSTATISTICS

// C++ STL Headers
#include <chrono>

// boost Headers
#include <boost\date_time\gregorian\gregorian.hpp>

// Qt SDK Headers
#include "QtCore\qstring.h"

#define DATE_DISPLAY_FORMAT "%1/%2/%3" // d/m/yyyy
#define DURATION_DISPLAY_FORMAT 'f'
#define DURATION_DISPLAY_PRECISION 2

using namespace std::chrono;
using namespace boost::gregorian;

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

  QString toString();

  QString getEngine() { return engine; };
  int getNodes() { return nodes; }
  int getCounter() { return counter; };

  QString getDurationInSeconds() {
    return QString::number(renderingDuration.count(), DURATION_DISPLAY_FORMAT, DURATION_DISPLAY_PRECISION);
  };

  QString getDate() {
    return QString(DATE_DISPLAY_FORMAT).arg(renderingDate.day()).arg(renderingDate.month()).arg(renderingDate.year());
  }

private:
  QString engine;
  int nodes;
  int counter;
  bool finished;

  high_resolution_clock::time_point startTime;
  high_resolution_clock::time_point endTime;
  duration<double> renderingDuration;

  date renderingDate;

  duration<double> calculateDuration();
};

#endif
