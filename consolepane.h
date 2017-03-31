#ifndef H_CONSOLE_PANE
#define H_CONSOLE_PANE

// DAZ Studio SDK Headers
#include "dzpane.h"

// Qt SDK Headers
#include "QtCore\qfile.h"

#define CONSOLE_PANE_LOG_FILE "C:/Users/todde/AppData/Roaming/DAZ 3D/Studio4/log.txt"
#define CONSOLE_PANE_MSG_OPEN_FAILED "The log file could not be opened."


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

  QFile m_logfile;

};

#endif
