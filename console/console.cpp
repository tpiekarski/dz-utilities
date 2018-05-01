#include "console.h"
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
    line.append(END_OF_LINE);
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
