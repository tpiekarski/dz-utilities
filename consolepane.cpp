// Console Headers
#include "consolepane.h"

// Qt SDK Headers
#include "QtCore\qfile.h"
#include "QtCore\qobject.h"
#include "QtCore\qstring.h"
#include "QtCore\qtextstream.h"
#include "QtGui\qboxlayout.h"
#include "QtGui\qmessagebox.h"
#include "QtGui\qtextbrowser.h"
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

  // Getting App data path and building full path to log file
  // (QFile expects only slashes and no backslashes in paths).
  QString dataPath(dzApp->getAppDataPath().replace(QString("\\"), QString("/")));
  QString logFullPath(QString("%1/log.txt").arg(dataPath));
  logFile.setFileName(logFullPath);

  // Opening log file
  if (logFile.open(QFile::ReadOnly | QFile::Text)) {
    QTextStream stream(&logFile);
    paneContent->setPlainText(stream.readAll());
    paneContent->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
  }
  else {
    QString msg(QString(tr("The log file %1 could not be opened.")).arg(logFullPath));
    QMessageBox::warning(0, tr("I/O-Error"), msg, QMessageBox::Ok);
    paneContent->setPlainText(msg);
  }

  paneLayout->addWidget(paneContent);

  setLayout(paneLayout);
  setMinimumSize(200, 150);

}

ConsolePane::~ConsolePane() {

  logFile.flush();
  logFile.close();

}
