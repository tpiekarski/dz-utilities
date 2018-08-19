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
#include "console_settings_dialog.h"
#include <dzapp.h>
#include <dzstyle.h>
#include <QtGui/qcolordialog.h>
#include <QtGui/qlabel.h>
#include <QtGui/qlayout.h>
#include <QtGui/qlineedit.h>
#include <QtGui/qpushbutton.h>

ConsoleSettingsDialog::ConsoleSettingsDialog(
  QWidget* parent, ConsoleSettings* settings
) : DzBasicDialog(parent, "ConsoleSettings") {
  this->settings = settings;
  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  layout()->setMargin(margin);
  layout()->setSpacing(margin);
  layout()->setSizeConstraint(QLayout::SetNoConstraint);

  formLayout = new QFormLayout(this);
  formLayout->setHorizontalSpacing(formLayout->horizontalSpacing() + CONSOLE_SETTINGS_FORM_ADDITIONAL_SPACING);
  formLayout->setVerticalSpacing(formLayout->verticalSpacing() + CONSOLE_SETTINGS_FORM_ADDITIONAL_SPACING);
  formWidget = new QWidget(this);
  formWidget->setLayout(formLayout);

  ConsoleSettingsDialog::addFilePathRow();
  ConsoleSettingsDialog::addFontSizeRow();
  ConsoleSettingsDialog::addHighlightColorRow();

  addWidget(formWidget);

  setWindowTitle("Console Settings");
  resize(QSize(CONSOLE_SETTINGS_DIALOG_WIDTH, 0).expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());
}

ConsoleSettingsDialog::~ConsoleSettingsDialog() {
  if (highlightColorLabel != nullptr) {
    formLayout->removeWidget(highlightColorLabel);
    delete highlightColorLabel;
    highlightColorLabel = nullptr;
  }

  if (highlightColorButton != nullptr) {
    formLayout->removeWidget(highlightColorButton);
    delete highlightColorButton;
    highlightColorButton = nullptr;
  }

  if (fontSizeLabel != nullptr) {
    formLayout->removeWidget(fontSizeLabel);
    delete fontSizeLabel;
    fontSizeLabel = nullptr;
  }

  if (fontSizeEditBox != nullptr) {
    formLayout->removeWidget(fontSizeEditBox);
    delete fontSizeEditBox;
    fontSizeEditBox = nullptr;
  }

  if (logFilePathLabel != nullptr) {
    formLayout->removeWidget(logFilePathLabel);
    delete logFilePathLabel;
    logFilePathLabel = nullptr;
  }

  if (logFilePathDisplayBox != nullptr) {
    formLayout->removeWidget(logFilePathDisplayBox);
    delete logFilePathDisplayBox;
    logFilePathDisplayBox = nullptr;
  }

  if (formLayout != nullptr) {
    delete formLayout;
    formLayout = nullptr;
  }

  if (formWidget != nullptr) {
    delete formWidget;
    formWidget = nullptr;
  }
}

void ConsoleSettingsDialog::selectHighlightColor() {
  newHighlightColor = QColorDialog::getColor(settings->getHighlightColor(), this);
}

void ConsoleSettingsDialog::addFilePathRow() {
  logFilePathLabel = new QLabel("Log File", formWidget);
  logFilePathLabel->setObjectName("ConsoleSettingsFilePathLabel");

  logFilePathDisplayBox = new QLineEdit(settings->getLogFilePath(), formWidget);
  logFilePathDisplayBox->setObjectName("ConsoleSettingsFilePathBox");
  logFilePathDisplayBox->setReadOnly(true);

  formLayout->addRow(logFilePathLabel, logFilePathDisplayBox);
}

void ConsoleSettingsDialog::addFontSizeRow() {
  fontSizeLabel = new QLabel("Font Size", formWidget);
  fontSizeLabel->setObjectName("ConsoleSettingsFontSizeLabel");

  QString fontSize = NULL;
  settings->getFontSize(&fontSize);
  fontSizeEditBox = new QLineEdit(fontSize, formWidget);
  fontSizeEditBox->setObjectName("ConsoleSettingsFontSizeEdit");
  fontSizeLabel->setBuddy(fontSizeEditBox);

  formLayout->addRow(fontSizeLabel, fontSizeEditBox);
}

void ConsoleSettingsDialog::addHighlightColorRow() {
  highlightColorLabel = new QLabel("Highlight Color", formWidget);
  highlightColorLabel->setObjectName("ConsoleSettingsHighlightColorLabel");

  highlightColorButton = new QPushButton("Select color...", formWidget);
  highlightColorButton->setObjectName("ConsoleSettingsHighlightColorButton");
  connect(highlightColorButton, SIGNAL(clicked()), this, SLOT(selectHighlightColor()));

  formLayout->addRow(highlightColorLabel, highlightColorButton);
}