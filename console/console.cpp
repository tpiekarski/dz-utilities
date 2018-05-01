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
  closeLog();
  logWatcher->removePath(logFullPath);
}

bool Console::openLog() {

  if (!logFile.open(QFile::ReadWrite | QFile::Text)) {
    return false;
  }

  logStream.setDevice(&logFile);

  return true;
}

bool Console::clearLog() {
  closeLog();

  return logFile.remove();
}

void Console::closeLog() {
  logStream.flush();
  logFile.close();
}