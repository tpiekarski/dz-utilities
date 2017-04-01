// Console Headers
#include "consolepane.h"

// Qt SDK Headers
#include "QtCore\qfile.h"
#include "QtCore\qobject.h"
#include "QtCore\qstring.h"
#include "QtCore\qtextstream.h"
#include "QtGui\qboxlayout.h"
#include "QtGui\qgroupbox.h"
#include "QtGui\qmessagebox.h"
#include "QtGui\qpushbutton.h"
#include "QtGui\qtextbrowser.h"
#include "QtGui\qtextcursor.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzstyle.h"

ConsolePane::ConsolePane() : DzPane("Console") {

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  // Definition of panes main layout
  QVBoxLayout *paneMainLayout = new QVBoxLayout();
  paneMainLayout->setMargin(margin);
  paneMainLayout->setSpacing(margin);
  setLayout(paneMainLayout);
  setMinimumSize(200, 150);

  // Definition of panes button group box
  QGroupBox *buttonGroupBox = new QGroupBox();
  QHBoxLayout *buttonGroupBoxLayout = new QHBoxLayout();
  buttonGroupBoxLayout->setMargin(margin);
  buttonGroupBoxLayout->setSpacing(margin);
  buttonGroupBox->setLayout(buttonGroupBoxLayout);

  // Definiton of control buttons and 
  QPushButton *reloadButton = new QPushButton("&Reload", this);
  QPushButton *clearButton = new QPushButton("&Clear", this);
  buttonGroupBoxLayout->addWidget(reloadButton);
  buttonGroupBoxLayout->addWidget(clearButton);
  connect(reloadButton, SIGNAL(clicked()), this, SLOT(reloadLog()));
  connect(clearButton, SIGNAL(clicked()), this, SLOT(clearLog()));

  paneMainLayout->addWidget(buttonGroupBox);

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

  paneMainLayout->addWidget(paneContent);

}

ConsolePane::~ConsolePane() {

  logFile.flush();
  logFile.close();

  // todo: disconnect buttons from click signal

}

void ConsolePane::reloadLog() {
  // todo: Implement method for reloading log file
}

void ConsolePane::clearLog() { 
  // todo: Implement method for clearing (deleting) log file
}