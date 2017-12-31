#ifndef H_RENDERSTATISTICS_PANE
#define H_RENDERSTATISTICS_PANE

#include<vector>

// Render Statistics Headers
#include "logger.h"
#include "statistics.h"

// // Qt SDK Headers
#include "QtGui\qtextbrowser.h"

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
  std::vector<RenderStatistics> statistics;
  RenderStatisticsLogger logger;
  DzRenderMgr *renderManager;
  QTextBrowser *statisticsBrowser;
  int renderingCounter;

  void setupPaneLayout();
  void updateStatisticsBrowser();
  QString getStatisticOutput();

};

#endif
