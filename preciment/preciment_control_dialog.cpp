/*
* Project:   dzUtilities::Preciment
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#include "preciment_control_dialog.h"
#include <dzstyle.h>

PrecimentControlDialog::PrecimentControlDialog(QWidget* parent, PrecimentSettingsManager* manager)
  : DzBasicDialog(parent, "PrecimentSettings"), m_manager(manager)
{
  m_layoutWidget = new QWidget(parent);
  m_layoutWidget->setObjectName("layoutWidget");

  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  layout()->setMargin(margin);
  layout()->setSpacing(margin);
  layout()->setSizeConstraint(QLayout::SetNoConstraint);

  m_dialogLayout = new QVBoxLayout(m_layoutWidget);
  m_dialogLayout->setObjectName("dialogLayout");
  m_dialogLayout->addWidget(buildPresetBox());
  m_dialogLayout->addWidget(buildMultiplierBox());

  addWidget(m_layoutWidget);

  setWindowTitle("Preciment Control");
  resize(QSize().expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());
}

PrecimentControlDialog::~PrecimentControlDialog() {

  if (m_multiplierLineEdit != nullptr) {
    m_multiplierLineEdit->setEnabled(false);
    m_multiplierFormLayout->removeWidget(m_multiplierLineEdit);
    delete m_multiplierLineEdit;
    m_multiplierLineEdit = nullptr;
  }

  if (m_multiplierLabel != nullptr) {
    m_multiplierLabel->setEnabled(false);
    m_multiplierFormLayout->removeWidget(m_multiplierLabel);
    delete m_multiplierLabel;
    m_multiplierLabel = nullptr;
  }

  if (m_multiplierFormLayout != nullptr) {
    delete m_multiplierFormLayout;
    m_multiplierFormLayout = nullptr;
  }

  if (m_multiplierBox != nullptr) {
    m_dialogLayout->removeWidget(m_multiplierBox);
    delete m_multiplierBox;
    m_multiplierBox = nullptr;
  }

  if (m_presetButtonRough != nullptr) {
    disconnect(m_presetButtonRough);
    m_presetButtonRough->setEnabled(false);
    m_presetBoxLayout->removeWidget(m_presetButtonRough);
    delete m_presetButtonRough;
    m_presetButtonRough = nullptr;
  }

  if (m_presetButtonNormal != nullptr) {
    disconnect(m_presetButtonNormal);
    m_presetButtonNormal->setEnabled(false);
    m_presetBoxLayout->removeWidget(m_presetButtonNormal);
    delete m_presetButtonNormal;
    m_presetButtonNormal = nullptr;
  }

  if (m_presetButtonFine != nullptr) {
    disconnect(m_presetButtonFine);
    m_presetButtonFine->setEnabled(false);
    m_presetBoxLayout->removeWidget(m_presetButtonFine);
    delete m_presetButtonFine;
    m_presetButtonFine = nullptr;
  }

  if (m_presetBoxLayout != nullptr) {
    delete m_presetBoxLayout;
    m_presetBoxLayout = nullptr;
  }

  if (m_presetBox != nullptr) {
    m_dialogLayout->removeWidget(m_presetBox);
    delete m_presetBox;
    m_presetBox = nullptr;
  }

  if (m_dialogLayout != nullptr) {
    delete m_dialogLayout;
    m_dialogLayout = nullptr;
  }

  if (m_layoutWidget != nullptr) {
    delete m_layoutWidget;
    m_layoutWidget = nullptr;
  }

}

QGroupBox* PrecimentControlDialog::buildPresetBox() {
  m_presetBox = new QGroupBox(m_layoutWidget);
  m_presetBox->setTitle("Presets");
  m_presetBox->setObjectName("presetBox");
  
  m_presetBoxLayout = new QHBoxLayout(m_presetBox);
  m_presetBoxLayout->setObjectName("presetBoxLayout");
  
  m_presetButtonFine = new QPushButton(m_presetBox);
  m_presetButtonFine->setText("&Fine");
  m_presetButtonFine->setObjectName("presetButtonFine");
  m_presetBoxLayout->addWidget(m_presetButtonFine);
  
  m_presetButtonNormal = new QPushButton(m_presetBox);
  m_presetButtonNormal->setText("&Normal");
  m_presetButtonNormal->setObjectName("presetButtonNormal");
  m_presetBoxLayout->addWidget(m_presetButtonNormal);

  m_presetButtonRough = new QPushButton(m_presetBox);
  m_presetButtonRough->setText("&Rough");
  m_presetButtonRough->setObjectName("presetButtonRough");
  m_presetBoxLayout->addWidget(m_presetButtonRough);

  // todo: implement preset buttons and enable them
  m_presetButtonFine->setEnabled(false);
  m_presetButtonNormal->setEnabled(false);
  m_presetButtonRough->setEnabled(false);

  return m_presetBox;
}

QGroupBox* PrecimentControlDialog::buildMultiplierBox() {
  m_multiplierBox = new QGroupBox(m_layoutWidget);
  m_multiplierBox->setTitle("Multiplier");
  m_multiplierBox->setObjectName("multiplierBox");

  m_multiplierFormLayout = new QFormLayout(m_multiplierBox);
  m_multiplierFormLayout->setObjectName("multiplierFormLayout");

  m_multiplierLabel = new QLabel(m_multiplierBox);
  m_multiplierLabel->setText("Value");
  m_multiplierLabel->setObjectName("multiplierLabel");

  m_multiplierLineEdit = new QLineEdit(m_multiplierBox);
  m_multiplierLineEdit->setObjectName("multiplierLineEdit");
  m_multiplierLineEdit->setText(m_manager->getSettings().getSingleMultiplierString());

  m_multiplierFormLayout->addRow(m_multiplierLabel, m_multiplierLineEdit);

  return m_multiplierBox;
}
