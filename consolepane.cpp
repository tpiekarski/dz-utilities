// Console Headers
#include "consolepane.h"

// Qt SDK Headers
#include "QtCore\qfile.h"
#include "QtCore\qobject.h"
#include "QtCore\qstring.h"
#include "QtCore\qtextstream.h"
#include "QtGui\qtextbrowser.h"
#include "QtGui\qboxlayout.h"
#include "QtGui\qmessagebox.h"
#include "QtGui\qtextcursor.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzstyle.h"

ConsolePane::ConsolePane() : DzPane("Console") {

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  // Definition of pane layout
  QVBoxLayout *paneLayout = new QVBoxLayout();
  paneLayout->setMargin(margin);
  paneLayout->setSpacing(margin);

  // Setting up and adding a qTextBrowser object for testing pane
  QTextBrowser *paneContent = new QTextBrowser();
  paneContent->setObjectName("Console");
  paneContent->setMinimumSize(200, 150);

  m_logfile.setFileName(CONSOLE_PANE_LOG_FILE);

  if (m_logfile.open(QFile::ReadOnly | QFile::Text)) {
    QTextStream stream(&m_logfile);
    paneContent->setPlainText(stream.readAll());
    paneContent->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
  }
  else {
    QMessageBox::warning(
      0,
      tr("I/O-Error"),
      tr(CONSOLE_PANE_MSG_OPEN_FAILED),
      QMessageBox::Ok
    );

    paneContent->setPlainText(tr(CONSOLE_PANE_MSG_OPEN_FAILED));
  }

  paneLayout->addWidget(paneContent);

  setLayout(paneLayout);
  setMinimumSize(200, 150);

}

ConsolePane::~ConsolePane() {

  m_logfile.flush();
  m_logfile.close();

}
