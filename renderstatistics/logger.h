#ifndef H_RENDERSTATISTICS_LOGGER
#define H_RENDERSTATISTICS_LOGGER

#include "statistics.h"
#include <QtCore/qstring.h>

#define DEFAULT_LOGGER_FORMAT "%1: %2"

/*
 * Class: RenderStatisticsLogger
 * Description: Convenient Logger class for simple message logging.
 *
*/
class RenderStatisticsLogger {

public:
  RenderStatisticsLogger(const bool debug);
  ~RenderStatisticsLogger();

  void log(const QString message);
  void log(const int number);
  void log(RenderStatistics* statistics);

private:
  bool debug;

};

#endif
