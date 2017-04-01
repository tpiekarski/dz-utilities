#ifndef H_CONSOLE_PANE
#define H_CONSOLE_PANE

// Console Headers
#include "console.h"

// Qt SDK Headers
#include "QtGui\qtextbrowser.h"

// DAZ Studio SDK Headers
#include "dzpane.h"

/*
 * Class: ConsolePane
 * Description: Main class for the console pane.
 */
class ConsolePane : public DzPane {

  Q_OBJECT

public:

  ConsolePane();
  ~ConsolePane();

private slots:
  
  void reloadLog();
  void clearLog();

private:

  Console* console;
  QTextBrowser* logBrowser;

  void displayLog();

};

#endif
