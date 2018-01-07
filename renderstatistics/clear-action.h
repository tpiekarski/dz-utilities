#ifndef H_RENDERSTATISTICS_CLEAR_ACTION
#define H_RENDERSTATISTICS_CLEAR_ACTION

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzaction.h"
#include "dzmainwindow.h"
#include "dzpanemgr.h"

// Qt SDK Headers
#include "QtGui\qkeysequence.h"

class RenderStatisticsClearAction : public DzAction {
  Q_OBJECT

public:
  RenderStatisticsClearAction();

protected:
  virtual QString getActionGroup() const { return "Render Statistics"; };
  virtual void executeAction();

};

#endif