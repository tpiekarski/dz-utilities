#ifndef H_RENDERSTATISTICS_PANE
#define H_RENDERSTATISTICS_PANE

#include<vector>

// Render Statistics Headers
#include "logger.h"
#include "statistics.h"

// // Qt SDK Headers
#include "QtCore\qlist.h"
#include "QtGui\qgridlayout.h"
#include "QtGui\qlabel.h"

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
  QVBoxLayout *paneLayout;
  QGridLayout *statisticsLayout;

  int renderingCounter;

  void setupPaneLayout();
  void insertSeparator(QGridLayout *layout, int rowSpan);
  void updateStatistics();
  QList<QLabel*> getStatisticOutputLabels();

};

#endif
