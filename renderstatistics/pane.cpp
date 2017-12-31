// Render Statistics Headers
#include "logger.h"
#include "pane.h"
#include "statistics.h"
#include "version.h"

// Qt SDK Headers
#include "QtCore\qobject.h"
#include "QtCore\qstring.h"
#include "QtGui\qboxlayout.h"
#include "QtGui\qmessagebox.h"
#include "QtGui\qtextbrowser.h"
#include "QtGui\qtextcursor.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzstyle.h"
#include "dzscene.h"
#include "dzrenderer.h"
#include "dzrendermgr.h"

RenderStatisticsPane::RenderStatisticsPane() : DzPane("Render Statistics") {
  logger = RenderStatisticsLogger();
  renderManager = dzApp->getRenderMgr();
  connectSignals();
  setupPaneLayout();
  renderingCounter = 0;
}

RenderStatisticsPane::~RenderStatisticsPane() { }

void RenderStatisticsPane::connectSignals() {
  connect(renderManager, SIGNAL(renderStarting()), this, SLOT(processStartRendering()));
  connect(renderManager, SIGNAL(renderFinished(bool)), this, SLOT(processFinishRendering()));
}

void RenderStatisticsPane::processStartRendering() {
  logger.log("Rendering started.");
  
  DzRenderer* renderer = renderManager->getActiveRenderer();
  statistics.push_back(RenderStatistics(renderer->getName(), dzScene->getNumNodes()));
}

void RenderStatisticsPane::processFinishRendering() {
  logger.log("Rendering finished.");

  RenderStatistics* currentStatistics = &statistics.back();
  currentStatistics->stopClock();
  currentStatistics->setCounter(++renderingCounter);
  
  logger.log(*currentStatistics);
  updateStatisticsBrowser();
}

void RenderStatisticsPane::setupPaneLayout() {
  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  QVBoxLayout *paneLayout = new QVBoxLayout();
  paneLayout->setMargin(margin);
  paneLayout->setSpacing(margin);

  statisticsBrowser = new QTextBrowser();
  statisticsBrowser->setObjectName(QString("%1Browser").arg(PLUGIN_NAME));
  statisticsBrowser->setMinimumSize(200, 150);
  statisticsBrowser->setHtml(getStatisticOutput());
  
  paneLayout->addWidget(statisticsBrowser);

  setLayout(paneLayout);
  setMinimumSize(200, 150);
}

void RenderStatisticsPane::updateStatisticsBrowser() {
  statisticsBrowser->clear();
  statisticsBrowser->setHtml(getStatisticOutput());
}

QString RenderStatisticsPane::getStatisticOutput() {
  QStringList renderingStatistics;

  for (RenderStatistics currentStatistics : statistics) {
    renderingStatistics.append(QString("<li>%1</li>")
      .arg(currentStatistics.toRow()));
  }

  return QString(
    "<h1>Render Statistics</h1>"
    "<div>"
    "<table style=\"font-size:14px\" border=\"0\" width=\"100%\">"
    "<tr><th align=\"left\">#</th><th align=\"left\">Engine</th><th align=\"left\">Nodes</th><th align=\"left\">Duration[s]</th></tr>"
    "%1"
    "</table>"
    "</div>"
  ).arg(renderingStatistics.join(QString("\n")));
}
