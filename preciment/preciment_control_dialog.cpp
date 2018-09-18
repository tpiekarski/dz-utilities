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

PrecimentControlDialog::PrecimentControlDialog(QWidget* parent, PrecimentSettings* settings) 
  : DzBasicDialog(parent, "PrecimentSettings")
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
  // todo: implement destructor (don't forget to clean up)
}

QGroupBox* PrecimentControlDialog::buildPresetBox() {
  m_presetBox = new QGroupBox(m_layoutWidget);
  m_presetBox->setTitle("Presets");
  m_presetBox->setObjectName("presetBox");
  
  m_presetsLayout = new QHBoxLayout(m_presetBox);
  m_presetsLayout->setObjectName("presetsLayout");
  
  m_presetBoxLayout = new QHBoxLayout();
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
  
  m_presetsLayout->addLayout(m_presetBoxLayout);

  return m_presetBox;
}

QGroupBox* PrecimentControlDialog::buildMultiplierBox() {
  m_multiplierBox = new QGroupBox(m_layoutWidget);
  m_multiplierBox->setTitle("Multiplier");
  m_multiplierBox->setObjectName("multiplierBox");

  m_multiplierLayout = new QHBoxLayout(m_multiplierBox);
  m_multiplierLayout->setObjectName("multiplierLayout");

  m_multiplierVBoxLayout = new QVBoxLayout();
  m_multiplierVBoxLayout->setObjectName("multiplierVBoxLayout");

  m_multiplierHBoxLayout = new QHBoxLayout();
  m_multiplierHBoxLayout->setObjectName("multiplierHBoxLayout");

  m_multiplierLabel = new QLabel(m_multiplierBox);
  m_multiplierLabel->setText("Value");
  m_multiplierLabel->setObjectName("multiplierLabel");
  m_multiplierHBoxLayout->addWidget(m_multiplierLabel);

  m_multiplierLineEdit = new QLineEdit(m_multiplierBox);
  m_multiplierLineEdit->setObjectName("multiplierLineEdit");
  m_multiplierHBoxLayout->addWidget(m_multiplierLineEdit);
  m_multiplierVBoxLayout->addLayout(m_multiplierHBoxLayout);

  m_multiplierLayout->addLayout(m_multiplierVBoxLayout);

  return m_multiplierBox;
}
