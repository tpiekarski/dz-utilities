#ifndef H_RENDERSTATISTICS
#define H_RENDERSTATISTICS

// C++ STL Headers
#include <chrono>
#include <iostream>
#include <locale>
#include <string>

// boost Headers
#include <boost\date_time\gregorian\gregorian.hpp>
#include <boost\date_time\posix_time\posix_time.hpp>
#include <boost\date_time\posix_time\ptime.hpp>

// Qt SDK Headers
#include "QtCore\qstring.h"

#define DATE_FACET_FORMAT "%m/%d/%Y"
#define TIME_FACET_FORMAT "%H:%M"
#define DURATION_DISPLAY_FORMAT 'f'
#define DURATION_DISPLAY_PRECISION 2

using namespace std;
using namespace std::chrono;
using namespace boost::gregorian;
using namespace boost::posix_time;

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

  QString getDurationInSeconds();
  QString getStartDate();
  QString getStartTime();

private:
  QString engine;
  int nodes;
  int counter;
  bool finished;

  high_resolution_clock::time_point startTime;
  high_resolution_clock::time_point endTime;
  duration<double> renderingDuration;

  ptime startDateTime;
  time_facet* timeFacet;
  date_facet* dateFacet;

  duration<double> calculateDuration();
};

#endif
