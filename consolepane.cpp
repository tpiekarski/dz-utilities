// Console Headers
#include "consolepane.h"

// Qt SDK Headers
#include "QtCore\qobject.h"
#include "QtGui\qtextbrowser.h"
#include "QtGui\qboxlayout.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzstyle.h"

ConsolePane::ConsolePane() : DzPane("Console") {

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  // Definition of pane layout
  QVBoxLayout *paneLayout = new QVBoxLayout();
  paneLayout->setMargin(margin);
  paneLayout->setSpacing(margin);

  QTextBrowser *paneContent = new QTextBrowser();
  paneContent->setObjectName("Console");
  paneContent->setMinimumSize(200, 150);

  paneLayout->addWidget(paneContent);

  setLayout(paneLayout);
  setMinimumSize(200, 150);

}

ConsolePane::~ConsolePane() {}
