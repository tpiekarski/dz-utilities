#ifndef H_CONSOLE_PROPERTIES_ACTION
#define H_CONSOLE_PROPERTIES_ACTION

#include "constants.h"
#include <dzaction.h>

class ConsolePropertiesAction : public DzAction {
  Q_OBJECT

public:
  ConsolePropertiesAction();

protected:
  virtual QString getActionGroup() const { return CONSOLE_ACTION_GROUP; };
  virtual void executeAction();

};

#endif

