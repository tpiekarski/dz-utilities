#ifndef H_RENDERSTATISTICS_LOGGER
#define H_RENDERSTATISTICS_LOGGER

// Render Statistics Headers
#include "statistics.h"

// Qt SDK Headers
#include "QtCore\qstring.h"

/*
 * Class: RenderStatisticsLogger
 * Description: Convenient Logger class for simple message logging.
 *
*/
class RenderStatisticsLogger {

public:
  RenderStatisticsLogger(bool debug);
  ~RenderStatisticsLogger();

  void log(QString message);
  void log(RenderStatistics statistics);

private:
  bool debug;

};

#endif
