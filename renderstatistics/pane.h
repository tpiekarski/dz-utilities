/*
* Project:   dzUtilities::RenderStatistics
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#ifndef H_RENDERSTATISTICS_PANE
#define H_RENDERSTATISTICS_PANE

#include "dzstatistics.h"
#include "logger.h"
#include "qstatisticslayout.h"
#include <dzactionmenu.h>
#include <dzpane.h>
#include <dzrendermgr.h>
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
  void processFinishRendering(bool succeeded);

private:
  vector<DzRenderStatistics> statistics;
  RenderStatisticsLogger* logger;
  DzRenderMgr* renderManager;
  QVBoxLayout* paneLayout;
  QStatisticsLayout* statisticsLayout;

  int renderingCounter;

  void setupPaneLayout();
  QString saveLastRenderImage(const int renderingCounter);
};
#endif
