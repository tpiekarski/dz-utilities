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

#include "logger.h"
#include "renderstatistics_constants.h"
#include "statistics.h"
#include "version.h"
#include <dzapp.h>
#include <QtCore/qstring.h>

RenderStatisticsLogger::RenderStatisticsLogger(const bool debug) {
  this->log("Starting logger for RenderStatistics.");

  this->debug = debug;
}

RenderStatisticsLogger::~RenderStatisticsLogger() {
  this->log("Stopping logger for RenderStatistics.");
}

void RenderStatisticsLogger::log(const QString message) {
  if (debug) {
    dzApp->log(QString(DEFAULT_LOGGER_FORMAT).arg(PLUGIN_NAME, message));
  }
}

void RenderStatisticsLogger::log(const int number) {
  if (debug) {
    dzApp->log(QString(DEFAULT_LOGGER_FORMAT).arg(PLUGIN_NAME, QString::number(number)));
  }
}

void RenderStatisticsLogger::log(RenderStatistics* statistics) {
  this->log(QString::fromLatin1(statistics->toString().c_str()));
}
