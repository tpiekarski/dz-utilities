#ifndef H_RENDERSTATISTICS_PANE
#define H_RENDERSTATISTICS_PANE

#include "logger.h"
#include "qstatisticslayout.h"
#include "statistics.h"
#include <dzactionmenu.h>
#include <dzpane.h>
#include <dzrendermgr.h>
#include <QtCore/qlist.h>
#include <QtGui/qgridlayout.h>
#include <vector>

#define COLUMNS 7
#define HEADING_ROWS 2
#define INITIAL_RENDERING_COUNTER 0
#define NOTHING ""
#define RENDER_FILE_NAME_TEMPLATE "render-%1.png"
#define RENDERSTATISTICS_DEBUG true;

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
  void buildOptionsMenu(DzActionMenu* menu) const override;

private slots:
  void connectSignals();
  void processStartRendering();
  void processFinishRendering();

private:
  vector<RenderStatistics> statistics;
  RenderStatisticsLogger* logger;
  DzRenderMgr* renderManager;
  QVBoxLayout* paneLayout;
  QStatisticsLayout* statisticsLayout;

  int renderingCounter;

  void setupPaneLayout();
  QString saveLastRenderImage(const int renderingCounter);
};

#endif
