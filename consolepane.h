#ifndef H_CONSOLE_PANE
#define H_CONSOLE_PANE

// Console Headers
#include "console.h"
#include "consolesettings.h"

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
  
  void displayLog();
  void reloadLog();
  void clearLog();
  void showProperties();

private:

  Console *console;
  ConsoleSettings *settings;
  QTextBrowser *logBrowser;

};

#endif
