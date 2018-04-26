#ifndef H_CONSOLE_CLEAR_ACTION
#define H_CONSOLE_CLEAR_ACTION

#include "constants.h"
#include <dzaction.h>

class ConsoleClearAction : public DzAction {
  Q_OBJECT

public:
  ConsoleClearAction();

protected:
  QString getActionGroup() const override { return CONSOLE_ACTION_GROUP; };
  void executeAction() override;

};

#endif

