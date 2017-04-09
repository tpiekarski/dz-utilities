// Console Headers
#include "consolepane.h"
#include "consolepropertiesdialog.h"
#include "consolesettings.h"
#include "constants.h"

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


ConsolePane::ConsolePane() : DzPane("Console") {

  console = new Console(dzApp->getAppDataPath());
  settings = new ConsoleSettings();
  settings->setLogFilePath(console->getLogFullPath());

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  float fontSize;

  // Definition of panes main layout
  QVBoxLayout *paneMainLayout = new QVBoxLayout();
  paneMainLayout->setMargin(margin);
  paneMainLayout->setSpacing(margin);
  setLayout(paneMainLayout);
  setMinimumSize(PANE_MIN_WIDTH, PANE_MIN_HEIGHT);

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
  logBrowser->setMinimumSize(PANE_MIN_WIDTH, PANE_MIN_HEIGHT);
  
  settings->getFontSize(&fontSize);
  logBrowser->setFontPointSize(fontSize);

  // Connecting signals to slots of the control buttons
  connect(reloadButton, SIGNAL(clicked()), this, SLOT(reloadLog()));
  connect(clearButton, SIGNAL(clicked()), this, SLOT(clearLog()));
  connect(propertiesButton, SIGNAL(clicked()), this, SLOT(showProperties()));

  paneMainLayout->addWidget(logBrowser);

  // Connecting to starting signal to display the log
  connect(dzApp, SIGNAL(starting()), this, SLOT(displayLog()));

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
  QString newFontSize;
  
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
  newFontSize = dialog->getNewFontSize();

  if (dialogResult == 1 && settings->fontSize != newFontSize ) {
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