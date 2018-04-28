#include "logger.h"
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
