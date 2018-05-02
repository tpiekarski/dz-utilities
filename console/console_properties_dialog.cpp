#include "console_properties_dialog.h"
#include "constants.h"
#include <QtGui/qlabel.h>
#include <QtGui/qlayout.h>
#include <QtGui/qlineedit.h>
#include <dzapp.h>
#include <dzstyle.h>

ConsolePropertiesDialog::ConsolePropertiesDialog(
  QWidget* parent, ConsoleSettings* settings
) : DzBasicDialog(parent, "ConsoleProperties") {

  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  QString fontSize;

  layout()->setMargin(margin);
  layout()->setSpacing(margin);
  layout()->setSizeConstraint(QLayout::SetNoConstraint);

  logFilePathLabel = new QLabel("Log File", this);
  logFilePathLabel->setObjectName("ConsolePropertiesFilePathLabel");
  addWidget(logFilePathLabel);

  logFilePathDisplayBox = new QLineEdit(settings->getLogFilePath(), this);
  logFilePathDisplayBox->setObjectName("ConsolePropertiesFilePathBox");
  logFilePathDisplayBox->setReadOnly(true);
  addWidget(logFilePathDisplayBox);

  fontSizeLabel = new QLabel("Font Size", this);
  fontSizeLabel->setObjectName("ConsolePropertiesFontSizeLabel");
  addWidget(fontSizeLabel);

  settings->getFontSize(&fontSize);
  fontSizeEditBox = new QLineEdit(fontSize, this);
  fontSizeEditBox->setObjectName("ConsolePropertiesFontSizeEdit");
  fontSizeLabel->setBuddy(fontSizeEditBox);
  addWidget(fontSizeEditBox);

  setWindowTitle("Console Properties");
  resize(QSize(SETTINGS_DIALOG_WIDTH, 0).expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());
}

ConsolePropertiesDialog::~ConsolePropertiesDialog() {
  if (fontSizeEditBox != nullptr) {
    delete(fontSizeEditBox);
    fontSizeEditBox = nullptr;
  }

  if (fontSizeLabel != nullptr) {
    delete(fontSizeLabel);
    fontSizeLabel = nullptr;
  }

  if (logFilePathDisplayBox != nullptr) {
    delete(logFilePathDisplayBox);
    logFilePathDisplayBox = nullptr;
  }

  if (logFilePathLabel != nullptr) {
    delete(logFilePathLabel);
    logFilePathLabel = nullptr;
  }

}

QString ConsolePropertiesDialog::getNewFontSize() {
  return fontSizeEditBox->text();
}
