// Console Headers
#include "consolepane.h"
#include "consolepropertiesdialog.h"
#include "consolesettings.h"

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
#include "dzmainwindow.h"
#include "dzstyle.h"


// Constants
static const int minWidth = 200;
static const int minHeight = 150;

ConsolePane::ConsolePane() : DzPane("Console") {

  console = new Console(dzApp->getAppDataPath());
  settings = new ConsoleSettings();

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  float fontSize;

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
  QPushButton *propertiesButton = new QPushButton("&Properties", this);

  buttonGroupBoxLayout->addWidget(reloadButton);
  buttonGroupBoxLayout->addWidget(clearButton);
  buttonGroupBoxLayout->addWidget(propertiesButton);

  paneMainLayout->addWidget(buttonGroupBox);
  
  // Setting up a QTextBrowser for displaying the log file
  logBrowser = new QTextBrowser();
  logBrowser->setObjectName("Console");
  logBrowser->setMinimumSize(minWidth, minHeight);
  
  settings->getFontSize(&fontSize);
  logBrowser->setFontPointSize(fontSize);

  displayLog();

  // Connecting signals to slots of the control buttons
  connect(reloadButton, SIGNAL(clicked()), this, SLOT(reloadLog()));
  connect(clearButton, SIGNAL(clicked()), this, SLOT(clearLog()));
  connect(propertiesButton, SIGNAL(clicked()), this, SLOT(showProperties()));

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

void ConsolePane::showProperties() {
  
  DzMainWindow *mainWindow;
  ConsolePropertiesDialog *dialog;
  int dialogResult;
  
  if (!(mainWindow = dzApp->getInterface())) {
    QMessageBox::warning(
      0,
      tr("Error"),
      tr("The main window is not available."),
      QMessageBox::Ok
    );

    return;
  }

  
  if (!(dialog = new ConsolePropertiesDialog(mainWindow, settings))) {
    QMessageBox::warning(
      0,
      tr("Error"),
      tr("The dialog for console settings could not be created."),
      QMessageBox::Ok
    );

    return;
  }

  dialogResult = dialog->exec();
  
  if (dialogResult == 1) {
    settings->setFontSize(dialog->getNewFontSize());

    float fontSize;
    settings->getFontSize(&fontSize);

    logBrowser->setFontPointSize(fontSize);
    reloadLog();
  }

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