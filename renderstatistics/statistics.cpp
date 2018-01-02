// Render Statistics Headers
#include "statistics.h"

RenderStatistics::RenderStatistics(QString engine, int nodes) {
  this->engine = engine;
  this->nodes = nodes;

  finished = false;
  startDateTime = second_clock::local_time();
  dateFacet = new date_facet();
  timeFacet = new time_facet();

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
  return duration_cast<duration<double>>(endTime - startTime);
}

QString RenderStatistics::getDurationInSeconds() {
  return QString::number(
    renderingDuration.count(), DURATION_DISPLAY_FORMAT, DURATION_DISPLAY_PRECISION
  );
};

QString RenderStatistics::getStartDate() {
  dateFacet->format(DATE_FACET_FORMAT);
  stringstream stringStream;
  stringStream.imbue(locale(locale::classic(), dateFacet));
  stringStream << startDateTime.date();

  return QString::fromLatin1(stringStream.str().c_str());
}

QString RenderStatistics::getStartTime() {
  timeFacet->format(TIME_FACET_FORMAT);
  stringstream stringStream;
  stringStream.imbue(locale(locale::classic(), timeFacet));
  stringStream << startDateTime;

  return QString::fromLatin1(stringStream.str().c_str());
}