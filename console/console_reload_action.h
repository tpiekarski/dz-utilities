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
  QString getActionGroup() const override { return CONSOLE_ACTION_GROUP; };
  void executeAction() override;

};

#endif

