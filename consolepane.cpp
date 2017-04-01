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

// Constants
static const float fontPointSize = 12.0;
static const int minWidth = 200;
static const int minHeight = 150;

ConsolePane::ConsolePane() : DzPane("Console") {

  console = new Console(dzApp->getAppDataPath());

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  // Definition of panes main layout
  QVBoxLayout *paneMainLayout = new QVBoxLayout();
  paneMainLayout->setMargin(margin);
  paneMainLayout->setSpacing(margin);
  setLayout(paneMainLayout);
  setMinimumSize(minWidth, minHeight);

  // Definition of panes button group box
  QGroupBox *buttonGroupBox = new QGroupBox();
  QHBoxLayout *buttonGroupBoxLayout = new QHBoxLayout();
  buttonGroupBoxLayout->setMargin(margin);
  buttonGroupBoxLayout->setSpacing(margin);
  buttonGroupBox->setLayout(buttonGroupBoxLayout);

  // Definiton of control buttons
  QPushButton *reloadButton = new QPushButton("&Reload", this);
  QPushButton *clearButton = new QPushButton("&Clear", this);
  buttonGroupBoxLayout->addWidget(reloadButton);
  buttonGroupBoxLayout->addWidget(clearButton);

  paneMainLayout->addWidget(buttonGroupBox);
  
  // Setting up a QTextBrowser for displaying the log file
  logBrowser = new QTextBrowser();
  logBrowser->setObjectName("Console");
  logBrowser->setMinimumSize(minWidth, minHeight);
  logBrowser->setFontPointSize(fontPointSize);

  displayLog();

  // Connecting signals to slots of the control buttons
  connect(reloadButton, SIGNAL(clicked()), this, SLOT(reloadLog()));
  connect(clearButton, SIGNAL(clicked()), this, SLOT(clearLog()));

  paneMainLayout->addWidget(logBrowser);
}

ConsolePane::~ConsolePane() {
  // todo: disconnect buttons from click signal
  console->closeLog();
}

void ConsolePane::displayLog() {

  if (console->openLog()) {
    logBrowser->setPlainText(console->getLog());
    logBrowser->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    console->closeLog();
  }
  else {
    QString msg(
      QString(
        tr("The log file %1 could not be opened.")
      ).arg(console->getLogFullPath())
    );

    QMessageBox::warning(0, tr("I/O-Error"), msg, QMessageBox::Ok);
    logBrowser->setPlainText(msg);
  }

}

void ConsolePane::reloadLog() {
  logBrowser->clear();
  displayLog();
}

void ConsolePane::clearLog() { 
  if (console->clearLog()) {
    logBrowser->clear();
    displayLog();
  }
  else {
    QString msg(
      QString(
        tr("The log file %1 could not be cleared.")
      ).arg(console->getLogFullPath())
    );
    QMessageBox::warning(0, tr("I/O-Error"), msg, QMessageBox::Ok);
  }
 
}