#ifndef H_RENDERSTATISTICS_CLEAR_ACTION
#define H_RENDERSTATISTICS_CLEAR_ACTION

#include <dzaction.h>

class RenderStatisticsClearAction : public DzAction {
  Q_OBJECT

public:
  RenderStatisticsClearAction();

protected:
  QString getActionGroup() const override { return "Render Statistics"; };
  void executeAction() override;

};

#endif