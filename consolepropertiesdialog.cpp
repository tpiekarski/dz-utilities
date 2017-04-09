// Console Headers
#include "consolepropertiesdialog.h"

// Qt SDK Headers
#include "QtGui\qlabel.h"
#include "QtGui\qlayout.h"
#include "QtGui\qlineedit.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzstyle.h"
#include "dzmainwindow.h"

ConsolePropertiesDialog::ConsolePropertiesDialog(
  QWidget *parent, ConsoleSettings *settings
) : DzBasicDialog(parent, "ConsoleProperties") {

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  QString fontSize;

  layout()->setMargin(margin);
  layout()->setSpacing(margin);
  layout()->setSizeConstraint(QLayout::SetNoConstraint);

  logFilePathLabel = new QLabel(tr("Log File"), this);
  logFilePathLabel->setObjectName("ConsolePropertiesFilePathLabel");
  addWidget(logFilePathLabel);

  logFilePathDisplayBox = new QLineEdit(settings->getLogFilePath(), this);
  logFilePathDisplayBox->setObjectName("ConsolePropertiesFilePathBox");
  logFilePathDisplayBox->setReadOnly(true);
  addWidget(logFilePathDisplayBox);

  fontSizeLabel = new QLabel(tr("Font Size"), this);
  fontSizeLabel->setObjectName("ConsolePropertiesFontSizeLabel");
  addWidget(fontSizeLabel);

  settings->getFontSize(&fontSize);
  fontSizeEditBox = new QLineEdit(fontSize, this);
  fontSizeEditBox->setObjectName("ConsolePropertiesFontSizeEdit");
  fontSizeLabel->setBuddy(fontSizeEditBox);
  addWidget(fontSizeEditBox);

  setWindowTitle(tr("Console Properties"));
  resize(QSize(DEFAULT_DIALOG_WIDTH, 0).expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());
}

ConsolePropertiesDialog::~ConsolePropertiesDialog() { }

QString ConsolePropertiesDialog::getNewFontSize() {
  return fontSizeEditBox->text();
}