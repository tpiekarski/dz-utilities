// C++ STL Headers
#include <chrono>

// boost Headers
#include <boost\date_time\gregorian\gregorian.hpp>

// Render Statistics Headers
#include "statistics.h"

// Qt SDK Headers
#include "QtCore\qstring.h"

using namespace std::chrono;

RenderStatistics::RenderStatistics(QString engine, int nodes) {
  this->engine = engine;
  this->nodes = nodes;
  this->finished = false;
  this->renderingDate = day_clock::local_day();

  startTime = high_resolution_clock::now();
}

RenderStatistics::~RenderStatistics() {}

void RenderStatistics::setCounter(int counter) {
  this->counter = counter;
}

void RenderStatistics::stopClock() {
  endTime = high_resolution_clock::now();
  renderingDuration = calculateDuration();
  finished = true;
}

QString RenderStatistics::toString() {
  return QString("Engine: %1, Nodes: %2, Duration [s]: %3")
    .arg(engine)
    .arg(nodes)
    .arg(getDurationInSeconds());
}

duration<double> RenderStatistics::calculateDuration() {
  return duration_cast<std::chrono::duration<double>>(endTime - startTime);
}