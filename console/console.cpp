/*
* Project:   dzUtilities::Console
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#include "console.h"
#include "console_constants.h"
#include <dzapp.h>
#include <QtGui/qwidget.h>

Console::Console(QWidget* parent, QString path) {
  // Building full path to log file, QFile expects only slashes
  const QString dataPath(path.replace(QString("\\"), QString("/")));
  logFullPath = QString("%1/log.txt").arg(dataPath);
  logFile.setFileName(logFullPath);

  logWatcher = new QFileSystemWatcher(parent);
  logWatcher->setObjectName("logWatcher");
  logWatcher->addPath(logFullPath);
}

Console::~Console() {
  logWatcher->removePath(logFullPath);

  if (logWatcher != nullptr) {
    delete logWatcher;
    logWatcher = nullptr;
  }
}

bool Console::openLog() {
  if (isLogOpen()) {
    return true;
  }

  if (!logFile.open(QFile::ReadWrite | QFile::Text)) {
    return false;
  }

  logStream.setDevice(&logFile);

  return true;
}

QString Console::getLogUpdates() {
  QString line = "";

  while (! logStream.atEnd()) {
    line.append(logStream.readLine());
    line.append(CONSOLE_END_OF_LINE);
  }

  return line;
}

QString Console::getLog() {
  return logStream.readAll();
}

void Console::resetLog() {
  if (logStream.pos() > 0) {
    logStream.seek(0);
  }
}

void Console::closeLog() {
  logStream.flush();
  logFile.close();
}
