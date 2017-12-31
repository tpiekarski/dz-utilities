// Render Statistics Headers
#include "logger.h"
#include "version.h"

// Qt SDK Headers
#include "QtCore\qstring.h"

// DAZ Studio SDK Headers
#include "dzapp.h"

RenderStatisticsLogger::RenderStatisticsLogger() {
  this->log("Starting logger for RenderStatistics.");
}

RenderStatisticsLogger::~RenderStatisticsLogger() {
  this->log("Stopping logger for RenderStatistics.");
}

void RenderStatisticsLogger::log(QString message) {
  dzApp->log(QString("%1: %2").arg(PLUGIN_NAME).arg(message));
}
