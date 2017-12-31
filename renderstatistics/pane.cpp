// Render Statistics Headers
#include "logger.h"
#include "pane.h"
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
#include "dzrendermgr.h"

RenderStatisticsPane::RenderStatisticsPane() : DzPane("Render Statistics") {
  logger = RenderStatisticsLogger();
  renderManager = dzApp->getRenderMgr();
  connectSignals();
  setupPaneLayout();
}

RenderStatisticsPane::~RenderStatisticsPane() { }

void RenderStatisticsPane::connectSignals() {
  connect(renderManager, SIGNAL(renderStarting()), this, SLOT(processStartRendering()));
  connect(renderManager, SIGNAL(renderFinished(bool)), this, SLOT(processFinishRendering()));
}

void RenderStatisticsPane::processStartRendering() {
  logger.log("Rendering started.");
}

void RenderStatisticsPane::processFinishRendering() {
  logger.log("Rendering finished.");
}

void RenderStatisticsPane::setupPaneLayout() {
  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  QVBoxLayout *paneLayout = new QVBoxLayout();
  paneLayout->setMargin(margin);
  paneLayout->setSpacing(margin);

  QTextBrowser *paneContent = new QTextBrowser();
  paneContent->setObjectName(QString("%1Browser").arg(PLUGIN_NAME));
  paneContent->setMinimumSize(200, 150);

  paneContent->setHtml(
    "<h1>Render Statistics</h1>"
    "<p>Not enough lines of code to gather all possible statistical data.</p>"
  );

  paneLayout->addWidget(paneContent);

  setLayout(paneLayout);
  setMinimumSize(200, 150);
}
