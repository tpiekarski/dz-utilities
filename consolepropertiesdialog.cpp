// Console Headers
#include "consolepropertiesdialog.h"

// Qt SDK Headers
#include "QtCore\qstring.h"
#include "QtGui\qlayout.h"


// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzstyle.h"
#include "dzmainwindow.h"

ConsolePropertiesDialog::ConsolePropertiesDialog(QWidget *parent) :
  DzBasicDialog(parent, "ConsoleProperties") {

  
  int generalMargin = style()->pixelMetric(DZ_PM_GeneralMargin);
  int buttonHeight = style()->pixelMetric(DZ_PM_ButtonHeight);
  int buttonMinWidth = style()->pixelMetric(DZ_PM_ButtonMinWidth);

  QSize windowSize = QSize(500, 100);

  setWindowTitle(tr("Console Properties"));

  resize(windowSize);
  
}

ConsolePropertiesDialog::~ConsolePropertiesDialog() { }