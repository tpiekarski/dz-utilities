/*
* Project:   dzUtilities::Tests
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#ifndef H_STATISTICS_TEST_MACROS
#define H_STATISTICS_TEST_MACROS

#include "statistics-test-constants.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <typeinfo>

using boost::posix_time::second_clock;
using std::locale;

#define STATISTICS_GET_SLEEP_SECONDS() \
  ((static_cast<double>(TEST_SLEEP_MILLISECONDS) / 1000.0))

#define STATISTICS_GET_STRING_REPRESENTATION() \
  QString("Engine: %1, Nodes: %2, Duration [s]: %3") \
    .arg((TEST_ENGINE), QString::number((TEST_NODES)), QString::number((STATISTICS_GET_SLEEP_SECONDS())))

#define STATISTICS_STOP_CLOCK(duration) \
  QTest::qSleep((duration)); \
  statistics->stopClock();

#define STATISTICS_BUILD_CURRENT_DATETIME(varname, facet) \
  ptime startDateTime = second_clock::local_time(); \
  stringstream stringStream; \
  stringStream.imbue(locale(locale::classic(), (facet))); \
  const type_info &typeInfo = typeid(facet); \
  const QString facetTypeName = QString::fromStdString(typeInfo.name()); \
  if (facetTypeName.contains("date_facet")) { \
    stringStream << startDateTime.date(); \
  } else if (facetTypeName.contains("time_facet")) { \
    stringStream << startDateTime; \
  } else { \
    QFAIL("Failed to identify passed facet into STATISTICS_GET_CURRENT_DATETIME macro, aborting unit test."); \
    stringStream.flush(); \
    stringStream.clear(); \
  } \
  stringStream.flush(); \
  const QString varname = QString::fromStdString(stringStream.str()); \
  stringStream.clear();

#endif


