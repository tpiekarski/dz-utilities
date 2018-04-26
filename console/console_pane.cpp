#include "console_pane.h"
#include "console_properties_dialog.h"
#include "console_settings.h"
#include "constants.h"
#include <QtCore/qfile.h>
#include <QtCore/qobject.h>
#include <QtCore/qstring.h>
#include <QtCore/qtextstream.h>
#include <QtGui/qboxlayout.h>
#include <QtGui/qmessagebox.h>
#include <QtGui/qtextbrowser.h>
#include <QtGui/qtextcursor.h>
#include <dzapp.h>
#include <dzmainwindow.h>
#include <dzstyle.h>

ConsolePane::ConsolePane() : DzPane("Console") {
  console = new Console(this, dzApp->getAppDataPath());
  settings = new ConsoleSettings();
  settings->setLogFilePath(console->getLogFullPath());

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  float fontSize;

  QVBoxLayout* paneMainLayout = new QVBoxLayout();
  paneMainLayout->setMargin(margin);
  paneMainLayout->setSpacing(margin);
  setLayout(paneMainLayout);
  setMinimumSize(PANE_MIN_WIDTH, PANE_MIN_HEIGHT);

  logBrowser = new QTextBrowser();
  logBrowser->setObjectName("Console");
  logBrowser->setMinimumSize(PANE_MIN_WIDTH, PANE_MIN_HEIGHT);

  settings->getFontSize(&fontSize);
  logBrowser->setFontPointSize(fontSize);

  paneMainLayout->addWidget(logBrowser);

  connect(dzApp, SIGNAL(starting()), this, SLOT(displayLog()));
  connect(console->getLogWatcher(), SIGNAL(fileChanged(const QString&)), this, SLOT(reloadLog()));
}

ConsolePane::~ConsolePane() {
  console->closeLog();
}

void ConsolePane::displayLog() {
  if (console->openLog()) {
    logBrowser->setPlainText(console->getLog());
    logBrowser->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    console->closeLog();
  }
  else {
    QString msg(QString(tr("The log file %1 could not be opened.")).arg(console->getLogFullPath()));

    QMessageBox::warning(0, tr("I/O-Error"), msg, QMessageBox::Ok);
    logBrowser->setPlainText(msg);
  }

}

void ConsolePane::reloadLog() {
  logBrowser->clear();
  displayLog();
}

void ConsolePane::showProperties() {

  DzMainWindow* mainWindow;
  ConsolePropertiesDialog* dialog;
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

void ConsolePane::buildOptionsMenu(DzActionMenu* menu) const {
  menu->insertAction("ConsoleClearAction");
  menu->insertAction("ConsoleReloadAction");
  menu->insertAction("ConsolePropertiesAction");
}