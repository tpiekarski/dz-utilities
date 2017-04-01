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

  console = new Console(dzApp->getAppDataPath());
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
  
  // Setting up a QTextBrowser for displaying the log file
  QTextBrowser *paneContent = new QTextBrowser();
  paneContent->setObjectName("Console");
  paneContent->setMinimumSize(200, 150);

  displayLog(paneContent);

  paneMainLayout->addWidget(paneContent);
}

ConsolePane::~ConsolePane() {
  // todo: disconnect buttons from click signal
  console->closeLog();
}

void ConsolePane::displayLog(QTextBrowser* textBrowser) {
  // Opening log file
  if (console->openLog()) {
    textBrowser->setPlainText(console->getLog());
    textBrowser->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    console->closeLog();
  }
  else {
    QString msg(QString(
      tr("The log file %1 could not be opened.")).arg(console->getLogFullPath())
    );

    QMessageBox::warning(0, tr("I/O-Error"), msg, QMessageBox::Ok);
    textBrowser->setPlainText(msg);
  }
}

void ConsolePane::reloadLog() {
  // todo: Implement method for reloading log file
}

void ConsolePane::clearLog() { 
  // todo: Implement method for clearing (deleting) log file
}