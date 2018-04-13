// Render Statistics Headers
#include "logger.h"
#include "pane.h"
#include "statistics.h"
#include "version.h"

// Qt SDK Headers
#include "QtCore\qobject.h"
#include "QtCore\qstring.h"
#include "QtGui\qboxlayout.h"
#include "QtGui\qlabel.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzrenderer.h"
#include "dzrendermgr.h"
#include "dzscene.h"
#include "dzstyle.h"

RenderStatisticsPane::RenderStatisticsPane() : DzPane("Render Statistics") {
  logger = RenderStatisticsLogger();
  renderManager = dzApp->getRenderMgr();
  connectSignals();
  setupPaneLayout();
  renderingCounter = 0;
}

RenderStatisticsPane::~RenderStatisticsPane() { }

void RenderStatisticsPane::clear() {
  if (statistics.size() > 0) {
    statistics.clear();
    statistics.shrink_to_fit();
  }

  if (statisticsLayout->rowCount() > HEADING_ROWS) {
    // todo: remove all widgets inside one QGridLayouts row
  }
}

void RenderStatisticsPane::connectSignals() {
  connect(renderManager, SIGNAL(renderStarting()), this, SLOT(processStartRendering()));
  connect(renderManager, SIGNAL(renderFinished(bool)), this, SLOT(processFinishRendering()));
}

void RenderStatisticsPane::buildOptionsMenu(DzActionMenu *menu) const {
  menu->insertAction("RenderStatisticsClearAction");
}

void RenderStatisticsPane::processStartRendering() {
  logger.log("Rendering started.");

  DzRenderer* renderer = renderManager->getActiveRenderer();
  statistics.push_back(RenderStatistics(renderer->getName().toStdString(), dzScene->getNumNodes()));
}

void RenderStatisticsPane::processFinishRendering() {
  logger.log("Rendering finished.");

  RenderStatistics* currentStatistics = &statistics.back();
  currentStatistics->stopClock();
  currentStatistics->setCounter(++renderingCounter);

  logger.log(*currentStatistics);
  statisticsLayout->update();
}

void RenderStatisticsPane::setupPaneLayout() {
  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  paneLayout = new QVBoxLayout(this);
  paneLayout->setMargin(margin);
  paneLayout->setSpacing(margin);

  statisticsLayout = new QStatisticsLayout(&statistics);
  paneLayout->addLayout(statisticsLayout);
  paneLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

  setLayout(paneLayout);
}
