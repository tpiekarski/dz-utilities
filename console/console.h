#ifndef H_CONSOLE
#define H_CONSOLE

#include <QtCore/qfile.h>
#include <QtCore/qfilesystemwatcher.h>
#include <QtCore/qstring.h>
#include <QtCore/qtextstream.h>
#include <QtGui/qwidget.h>

/*
 * Class: Console
 * Description: Console class wrapping access and handling of the log file.
 */
class Console {

public:
  Console(QWidget* parent, QString path);
  ~Console();

  bool openLog();
  bool clearLog();
  void closeLog();

  QString getLog() { return logStream.readAll(); };
  QString getLogFullPath() { return logFullPath; };
  QFileSystemWatcher* getLogWatcher() { return logWatcher; };

private:
  QString logFullPath;
  QFile logFile;
  QFileSystemWatcher* logWatcher;
  QTextStream logStream;

};

#endif