#ifndef H_CONSOLE_PANE_ACTION
#define H_CONSOLE_PANE_ACTION

// DAZ Studio SDK Headers
#include "dzaction.h"

/*
* Class: ConsolePaneAction
* Description: Registration of a menu action for toggling console pane on/off.
*/
class ConsolePaneAction : public DzPaneAction {

  Q_OBJECT

public:
  ConsolePaneAction() : DzPaneAction("ConsolePane") {}

};

#endif
