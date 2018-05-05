/*
* Project:   dzUtilities::RenderStatistics
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

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
