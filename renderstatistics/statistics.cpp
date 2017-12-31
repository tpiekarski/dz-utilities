
#include<chrono>

// Render Statistics Headers
#include "statistics.h"

// Qt SDK Headers
#include "QtCore\qstring.h"

using namespace std::chrono;

#define DURATION_DISPLAY_FORMAT 'f'
#define DURATION_DISPLAY_PRECISION 2

RenderStatistics::RenderStatistics(QString engine, int nodes) {
  this->engine = engine;
  this->nodes = nodes;
  this->finished = false;

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

QString RenderStatistics::getDurationInSeconds() {
  return QString::number(
    renderingDuration.count(), 
    DURATION_DISPLAY_FORMAT, 
    DURATION_DISPLAY_PRECISION
  );
}

QString RenderStatistics::toString() {
  return QString("Engine: %1, Nodes: %2, Duration [s]: %3")
    .arg(engine)
    .arg(nodes)
    .arg(getDurationInSeconds());
}

QString RenderStatistics::toRow() {
  return QString("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td>")
    .arg(counter)
    .arg(engine)
    .arg(nodes)
    .arg(getDurationInSeconds());
}

duration<double> RenderStatistics::calculateDuration() {
  return duration_cast<std::chrono::duration<double>>(endTime - startTime);
}