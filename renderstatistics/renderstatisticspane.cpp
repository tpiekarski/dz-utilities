// Console Headers
#include "renderstatisticspane.h"

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

RenderStatisticsPane::RenderStatisticsPane() : DzPane("Render Statistics") {

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  QVBoxLayout *paneLayout = new QVBoxLayout();
  paneLayout->setMargin(margin);
  paneLayout->setSpacing(margin);

  QTextBrowser *paneContent = new QTextBrowser();
  paneContent->setObjectName("Render Statistics");
  paneContent->setMinimumSize(200, 150);

  paneContent->setHtml(
    "<h1>Render Statistics</h1>"
    "<p>...</p>"
  );

  paneLayout->addWidget(paneContent);

  setLayout(paneLayout);
  setMinimumSize(200, 150);

}

RenderStatisticsPane::~RenderStatisticsPane() { }
