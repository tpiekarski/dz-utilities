#ifndef H_RENDERSTATISTICS_CLEAR_ACTION
#define H_RENDERSTATISTICS_CLEAR_ACTION

// DAZ Studio SDK Headers
#include "dzaction.h"

class RenderStatisticsClearAction : public DzAction {
  Q_OBJECT

public:
  RenderStatisticsClearAction();

protected:
  virtual QString getActionGroup() const { return "Render Statistics"; };
  virtual void executeAction();

};

#endif