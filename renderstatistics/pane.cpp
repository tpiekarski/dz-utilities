// Render Statistics Headers
#include "logger.h"
#include "pane.h"
#include "statistics.h"
#include "version.h"

// Qt SDK Headers
#include "QtCore\qobject.h"
#include "QtCore\qstring.h"
#include "QtGui\qboxlayout.h"
#include "QtGui\qcolor.h"
#include "QtGui\qframe.h"
#include "QtGui\qgridlayout.h"
#include "QtGui\qlabel.h"
#include "QtGui\qpalette.h"

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

void RenderStatisticsPane::connectSignals() {
  connect(renderManager, SIGNAL(renderStarting()), this, SLOT(processStartRendering()));
  connect(renderManager, SIGNAL(renderFinished(bool)), this, SLOT(processFinishRendering()));
}

void RenderStatisticsPane::processStartRendering() {
  logger.log("Rendering started.");

  DzRenderer* renderer = renderManager->getActiveRenderer();

  string test = renderer->getName().toStdString();

  statistics.push_back(RenderStatistics(renderer->getName().toStdString(), dzScene->getNumNodes()));
}

void RenderStatisticsPane::processFinishRendering() {
  logger.log("Rendering finished.");

  RenderStatistics* currentStatistics = &statistics.back();
  currentStatistics->stopClock();
  currentStatistics->setCounter(++renderingCounter);

  logger.log(*currentStatistics);
  updateStatistics();
}

void RenderStatisticsPane::setupPaneLayout() {
  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  paneLayout = new QVBoxLayout();
  paneLayout->setMargin(margin);
  paneLayout->setSpacing(margin);

  statisticsLayout = new QGridLayout();

  QList<QLabel*> labels;
  labels.append(new QLabel("#"));
  labels.append(new QLabel("Engine"));
  labels.append(new QLabel("Nodes"));
  labels.append(new QLabel("Date"));
  labels.append(new QLabel("Time"));
  labels.append(new QLabel("Duration [s]"));

  int row = 0;

  for (QLabel* label : labels) {
    label->setFixedHeight(15);
    statisticsLayout->addWidget(label, 0, row++);
  }

  insertSeparator(statisticsLayout, 1, COLUMNS);

  paneLayout->addLayout(statisticsLayout);
  paneLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

  setLayout(paneLayout);
}

void RenderStatisticsPane::insertSeparator(QGridLayout *layout, int row, int columnSpan) {
  QFrame *separator = new QFrame(this);
  separator->setLineWidth(1);
  separator->setMidLineWidth(1);
  separator->setFrameShape(QFrame::HLine);
  separator->setPalette(QPalette(QColor(0, 0, 0)));

  layout->addWidget(separator, row, 0, 1, columnSpan);
}

void RenderStatisticsPane::updateStatistics() {
  int currentColumn = 0;
  int currentRow = statisticsLayout->rowCount();

  for (QLabel* label : getStatisticOutputLabels()) {
    statisticsLayout->addWidget(label, currentRow, currentColumn++);
  }

}

QList<QLabel*> RenderStatisticsPane::getStatisticOutputLabels() {
  QList<QLabel*> outputLabels;

  RenderStatistics lastStatistics = statistics.back();

  outputLabels.append(new QLabel(QString::number(lastStatistics.getCounter())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics.getEngine())));
  outputLabels.append(new QLabel(QString::number(lastStatistics.getNodes())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics.getStartDate())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics.getStartTime())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics.getDurationInSeconds())));

  return outputLabels;
}