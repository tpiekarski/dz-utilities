/*
* Project:   dzUtilities::Console
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#include "console_constants.h"
#include "console_properties_dialog.h"
#include <QtGui/qlabel.h>
#include <QtGui/qlayout.h>
#include <QtGui/qlineedit.h>
#include <QtGui/qpushbutton.h>
#include <dzapp.h>
#include <dzstyle.h>
#include <QtGui/qcolordialog.h>

ConsolePropertiesDialog::ConsolePropertiesDialog(
  QWidget* parent, ConsoleSettings* settings
) : DzBasicDialog(parent, "ConsoleProperties") {
  this->settings = settings;
  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

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

  QString fontSize = NULL;
  settings->getFontSize(&fontSize);
  fontSizeEditBox = new QLineEdit(fontSize, this);
  fontSizeEditBox->setObjectName("ConsolePropertiesFontSizeEdit");
  fontSizeLabel->setBuddy(fontSizeEditBox);
  addWidget(fontSizeEditBox);

  highlightColorLabel = new QLabel("Highlight Color", this);
  highlightColorLabel->setObjectName("ConsolePropertiesHighlightColorLabel");
  addWidget(highlightColorLabel);

  highlightColorButton = new QPushButton("Select color...", this);
  highlightColorButton->setObjectName("ConsolePropertiesHighlightColorButton");
  connect(highlightColorButton, SIGNAL(clicked()), this, SLOT(selectHighlightColor()));
  addWidget(highlightColorButton);

  setWindowTitle("Console Properties");
  resize(QSize(SETTINGS_DIALOG_WIDTH, 0).expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());
}

ConsolePropertiesDialog::~ConsolePropertiesDialog() {
  if (highlightColorButton != nullptr) {
    delete(highlightColorButton);
    highlightColorButton = nullptr;
  }
  
  if (highlightColorLabel != nullptr) {
    delete(highlightColorLabel);
    highlightColorLabel = nullptr;
  }
  
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

void ConsolePropertiesDialog::selectHighlightColor() {
  newHighlightColor = QColorDialog::getColor(settings->getHighlightColor(), this);
}
