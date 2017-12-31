#ifndef H_RENDERSTATISTICS_PANE
#define H_RENDERSTATISTICS_PANE

// Render Statistics Headers
#include "logger.h"

// DAZ Studio SDK Headers
#include "dzpane.h"
#include "dzrendermgr.h"

/*
 * Class: RenderStatisticsPane
 * Description: Main class for the render statistics pane.
 *
 */
class RenderStatisticsPane : public DzPane {

  Q_OBJECT

public:

  RenderStatisticsPane();
  ~RenderStatisticsPane();

private slots:

  void processStartRendering();
  void processFinishRendering();

  void connectSignals();

private:
  RenderStatisticsLogger logger;
  DzRenderMgr *renderManager;

  void setupPaneLayout();

};

#endif
