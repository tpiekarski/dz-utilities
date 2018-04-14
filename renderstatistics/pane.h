#ifndef H_RENDERSTATISTICS_PANE
#define H_RENDERSTATISTICS_PANE

#include<vector>

// Render Statistics Headers
#include "logger.h"
#include "statistics.h"
#include "qstatisticslayout.h"

// Qt SDK Headers
#include "QtCore\qlist.h"
#include "QtGui\qgridlayout.h"
#include "QtGui\qlabel.h"

// DAZ Studio SDK Headers
#include "dzactionmenu.h"
#include "dzpane.h"
#include "dzrendermgr.h"

#define HEADING_ROWS 2
#define COLUMNS 7

#define RENDER_FILE_NAME_TEMPLATE "render-%1.png"
#define NOTHING ""

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
  void clear();

protected:
  virtual void buildOptionsMenu(DzActionMenu *menu) const;

private slots:
  void connectSignals();
  void processStartRendering();
  void processFinishRendering();

private:
  vector<RenderStatistics> statistics;
  RenderStatisticsLogger logger;
  DzRenderMgr *renderManager;
  QVBoxLayout *paneLayout;
  QStatisticsLayout *statisticsLayout;

  int renderingCounter;

  void setupPaneLayout();
  QString saveLastRenderImage(int renderingCounter);
};

#endif
