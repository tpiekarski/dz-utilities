#ifndef H_CONSOLE_CLEAR_ACTION
#define H_CONSOLE_CLEAR_ACTION

#include "constants.h"
#include <dzaction.h>

class ConsoleClearAction : public DzAction {
  Q_OBJECT

public:
  ConsoleClearAction();

protected:
  virtual QString getActionGroup() const { return CONSOLE_ACTION_GROUP; };
  virtual void executeAction();

};

#endif

