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

#include "rs_constants.h"
#include "rs_statistics.h"

using boost::posix_time::second_clock;
using std::chrono::duration_cast;
using std::locale;

RenderStatistics::RenderStatistics(const string engine, const int nodes) {
  this->engine = engine;
  this->nodes = nodes;
  this->counter = 0;

  finished = false;
  succeeded = false;
  startDateTime = second_clock::local_time();

  date_facet* dateFacet = new date_facet();
  dateFacet->format(DATE_FACET_FORMAT);
  dateStream = new stringstream;
  dateStream->imbue(locale(locale::classic(), dateFacet));

  time_facet* timeFacet = new time_facet();
  timeFacet->format(TIME_FACET_FORMAT);
  timeStream = new stringstream();
  timeStream->imbue(locale(locale::classic(), timeFacet));

  startTime = high_resolution_clock::now();
}

void RenderStatistics::setCounter(const int counter) {
  this->counter = counter;
}

void RenderStatistics::setRenderImage(const string renderImage) {
  this->renderImage = renderImage;
}

void RenderStatistics::setSucceeded(const bool succeeded) {
  this->succeeded = succeeded;
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
  *dateStream << startDateTime.date();
  const string date = dateStream->str();
  dateStream->clear();

  return date;
}

string RenderStatistics::getStartTime() {
  *timeStream << startDateTime;
  const string time = timeStream->str();
  timeStream->clear();

  return time;
}