#ifndef H_CONSOLE
#define H_CONSOLE

#include <QtCore/qfile.h>
#include <QtCore/qfilesystemwatcher.h>
#include <QtCore/qstring.h>
#include <QtCore/qtextstream.h>

#define END_OF_LINE "\n"

/*
 * Class: Console
 * Description: Console class wrapping access and handling of the log file.
 */
class Console {

public:
  Console(QWidget* parent, QString path);
  ~Console();

  bool openLog();
  void closeLog();

  QString getLogUpdates();
  QString getLog();
  void resetLog();
  QString getLogFullPath() { return logFullPath; };
  QFileSystemWatcher* getLogWatcher() { return logWatcher; };
  bool isLogOpen() { return logFile.isOpen() && logFile.isReadable(); };

private:
  QString logFullPath;
  QFile logFile;
  QFileSystemWatcher* logWatcher;
  QTextStream logStream;

};

#endif