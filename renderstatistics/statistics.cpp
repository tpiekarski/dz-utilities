// C++ STL Headers
#include <chrono>
#include <iostream>
#include <locale>
#include <string>

// boost Headers
#include <boost\date_time\gregorian\gregorian.hpp>
#include <boost\date_time\posix_time\posix_time.hpp>
#include <boost\date_time\posix_time\ptime.hpp>

// Render Statistics Headers
#include "statistics.h"

// Qt SDK Headers
#include "QtCore\qstring.h"

using namespace std;
using namespace std::chrono;
using namespace boost::posix_time;

RenderStatistics::RenderStatistics(QString engine, int nodes) {
  this->engine = engine;
  this->nodes = nodes;

  finished = false;
  startDateTime = second_clock::local_time();
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

QString RenderStatistics::getStartDate() {
  date startDate = startDateTime.date();

  return QString(DATE_DISPLAY_FORMAT)
    .arg(startDate.day())
    .arg(startDate.month())
    .arg(startDate.year());
}

QString RenderStatistics::getStartTime() {
  time_facet* timeFacet = new time_facet();
  timeFacet->format(TIME_FACET_DISPLAY_FORMAT);

  stringstream stream;
  stream.imbue(locale(locale::classic(), timeFacet));
  stream << startDateTime;

  return QString::fromLatin1(stream.str().c_str());
}