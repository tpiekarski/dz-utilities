// Render Statistics Headers
#include "statistics.h"

RenderStatistics::RenderStatistics(const string engine, const int nodes) {
  this->engine = engine;
  this->nodes = nodes;
  this->counter = 0;

  finished = false;
  startDateTime = second_clock::local_time();
  dateFacet = new date_facet();
  timeFacet = new time_facet();

  startTime = high_resolution_clock::now();
}

RenderStatistics::~RenderStatistics() {}

void RenderStatistics::setCounter(const int counter) {
  this->counter = counter;
}

void RenderStatistics::setRenderImage(const string renderImage) {
  this->renderImage = renderImage;
}

void RenderStatistics::stopClock() {
  endTime = high_resolution_clock::now();
  renderingDuration = calculateDuration();
  finished = true;
}

string RenderStatistics::toString() {
  stringstream stringStream;
  stringStream << "Engine: " << engine << ", Nodes: " << nodes << ", Duration [s]: " << getDurationInSeconds();

  return stringStream.str();
}

duration<double> RenderStatistics::calculateDuration() {
  return duration_cast<duration<double>>(endTime - startTime);
}

string RenderStatistics::getDurationInSeconds() {
  stringstream stringStream;
  stringStream.precision(DURATION_DISPLAY_PRECISION);
  stringStream << renderingDuration.count();

  return stringStream.str();
};

string RenderStatistics::getStartDate() {
  dateFacet->format(DATE_FACET_FORMAT);
  stringstream stringStream;
  stringStream.imbue(locale(locale::classic(), dateFacet));
  stringStream << startDateTime.date();

  return stringStream.str();
}

string RenderStatistics::getStartTime() {
  timeFacet->format(TIME_FACET_FORMAT);
  stringstream stringStream;
  stringStream.imbue(locale(locale::classic(), timeFacet));
  stringStream << startDateTime;

  return stringStream.str();
}