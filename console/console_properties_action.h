#ifndef H_CONSOLE_PROPERTIES_ACTION
#define H_CONSOLE_PROPERTIES_ACTION

#include "constants.h"
#include <dzaction.h>

class ConsolePropertiesAction : public DzAction {
  Q_OBJECT

public:
  ConsolePropertiesAction();
  ~ConsolePropertiesAction() = default;

protected:
  QString getActionGroup() const override { return CONSOLE_ACTION_GROUP; };
  void executeAction() override;

};

#endif

