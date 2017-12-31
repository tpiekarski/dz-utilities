#ifndef H_RENDERSTATISTICS_LOGGER
#define H_RENDERSTATISTICS_LOGGER

// Qt SDK Headers
#include "QtCore\qstring.h"

/*
 * Class: RenderStatisticsLogger
 * Description: Convenient Logger class for simple message logging.
 *
*/
class RenderStatisticsLogger {

public:
  RenderStatisticsLogger();
  ~RenderStatisticsLogger();

  void log(QString message);

};

#endif
