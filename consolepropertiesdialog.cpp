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

  // Definition of dialog elements
  fontSizeLabel = new QLabel(tr("Font Size"), this);
  settings->getFontSize(&fontSize);
  fontSizeEdit = new QLineEdit(fontSize, this);

  fontSizeLabel->setObjectName("ConsolePropertiesFontSizeLabel");
  fontSizeEdit->setObjectName("ConsolePropertiesFontSizeEdit");
  fontSizeLabel->setBuddy(fontSizeEdit);

  addWidget(fontSizeLabel);
  addWidget(fontSizeEdit);

  setWindowTitle(tr("Console Properties"));
  resize(QSize(200, 0).expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());
}

ConsolePropertiesDialog::~ConsolePropertiesDialog() { }

QString ConsolePropertiesDialog::getNewFontSize() {
  return fontSizeEdit->text();
}