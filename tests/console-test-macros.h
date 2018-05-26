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

#ifndef H_CONSOLE_TEST_MACROS
#define H_CONSOLE_TEST_MACROS

#define TESTLOG_OPEN() \
  if (!console->openLog() || !console->isLogOpen()) { \
    QFAIL("Failed opening log file, aborting unit test."); \
  }

#define TESTLOG_CLOSE() \
  console->closeLog();

#define TESTLOG_WRITE(data, mode) \
  QFile* logFile = new QFile(console->getLogFullPath()); \
  if (!logFile->open((mode) | QFile::Text)) { \
    QFAIL("Failed opening log file for writing test data, aborting unit test."); \
  } \
  QTextStream logStream(logFile); \
  logStream << (data); \
  logStream.flush(); \
  logFile->flush(); \
  logFile->close(); \
  if (logFile != nullptr) { \
    delete logFile; \
    logFile = nullptr; \
  }

#endif
