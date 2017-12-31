#ifndef H_CONSOLE
#define H_CONSOLE

// Qt SDK Headers
#include "QtCore\qfile.h"
#include "QtCore\qstring.h"
#include "QtCore\qtextstream.h"

/*
 * Class: Console
 * Description: Console class wrapping access and handling of the log file.
 */
class Console {

public:

  Console(QString path);
  ~Console();

  bool openLog();
  bool clearLog();
  void closeLog();

  QString getLog();
  QString getLogFullPath();

private:

  QString logFullPath;
  QFile logFile;
  QTextStream logStream;

};

#endif