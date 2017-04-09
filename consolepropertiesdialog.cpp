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

ConsolePropertiesDialog::ConsolePropertiesDialog(QWidget *parent) :
  DzBasicDialog(parent, "ConsoleProperties") {

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  layout()->setMargin(margin);
  layout()->setSpacing(margin);
  layout()->setSizeConstraint(QLayout::SetNoConstraint);

  // Definition of dialog elements
  fontSizeLabel = new QLabel(tr("Font Size"), this);
  fontSizeEdit = new QLineEdit("12", this);

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

float ConsolePropertiesDialog::getFontPointSize() {
  bool conversion;
  float fontSize;
  
  fontSize = fontSizeEdit->text().toFloat(&conversion);

  return (conversion) ? fontSize : defaultFontPointSize;
}