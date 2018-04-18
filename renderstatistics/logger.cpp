// Render Statistics Headers
#include "logger.h"
#include "statistics.h"
#include "version.h"

// Qt SDK Headers
#include "QtCore\qstring.h"

// DAZ Studio SDK Headers
#include "dzapp.h"

RenderStatisticsLogger::RenderStatisticsLogger(bool debug) {
  this->log("Starting logger for RenderStatistics.");

  this->debug = debug;
}

RenderStatisticsLogger::~RenderStatisticsLogger() {
  this->log("Stopping logger for RenderStatistics.");
}

void RenderStatisticsLogger::log(QString message) {
  if (debug) {
    dzApp->log(QString("%1: %2").arg(PLUGIN_NAME).arg(message));
  }
}

void RenderStatisticsLogger::log(RenderStatistics statistics) {
  this->log(QString::fromLatin1(statistics.toString().c_str()));
}
