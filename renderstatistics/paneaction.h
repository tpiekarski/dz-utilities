#ifndef H_RENDERSTATISTICS_PANE_ACTION
#define H_RENDERSTATISTICS_PANE_ACTION

// DAZ Studio SDK Headers
#include "dzaction.h"

/*
 * Class: RenderStatisticsPaneAction
 * Description: Registration of a menu action for toggling
 * render statistics pane on/off.
 *
 */
class RenderStatisticsPaneAction : public DzPaneAction {

  Q_OBJECT

public:
  RenderStatisticsPaneAction() : DzPaneAction("RenderStatisticsPane") {}

};

#endif
