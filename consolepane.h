#ifndef H_CONSOLE_PANE
#define H_CONSOLE_PANE

// DAZ Studio SDK Headers
#include "dzpane.h"

// Qt SDK Headers
#include "QtCore\qfile.h"

/*
 * Class: ConsolePane
 * Description: Main class for the console pane.
 *
 */
class ConsolePane : public DzPane {

  Q_OBJECT

public:

  ConsolePane();
  ~ConsolePane();

private:

  QFile logFile;

};

#endif
