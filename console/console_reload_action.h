#ifndef H_CONSOLE_RELOAD_ACTION
#define H_CONSOLE_RELOAD_ACTION

// Console Headers
#include "constants.h"

// DAZ Studio SDK Headers
#include <dzaction.h>

class ConsoleReloadAction : public DzAction {
  Q_OBJECT

public:
  ConsoleReloadAction();

protected:
  virtual QString getActionGroup() const { return CONSOLE_ACTION_GROUP; };
  virtual void executeAction();

};

#endif

