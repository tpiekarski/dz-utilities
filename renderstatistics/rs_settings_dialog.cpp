/*
* Project:   dzUtilities::RenderStatistics
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#include "rs_constants.h"
#include "rs_settings_dialog.h"
#include <dzapp.h>
#include <dzstyle.h>
#include <QtCore/qsize.h>
#include <QtGui/qlabel.h>
#include <QtGui/qlayout.h>
#include <QtGui/qspinbox.h>
#include <QtGui/qwidget.h>

RenderStatisticsSettingsDialog::RenderStatisticsSettingsDialog(
  QWidget* parent, RenderStatisticsSettings* settings
) : DzBasicDialog(parent, "RenderStatisticsSettings") 
{
  this->settings = settings;
  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  layout()->setMargin(margin);
  layout()->setSpacing(margin);
  layout()->setSizeConstraint(QLayout::SetNoConstraint);

  settingsLayout = new QFormLayout();
  settingsLayout->setMargin(RS_SETTINGS_DIALOG_MARGIN);
  settingsLayout->setSpacing(RS_SETTINGS_DIALOG_SPACING);

  RenderStatisticsSettingsDialog::addRenderImageWidthRow();
  RenderStatisticsSettingsDialog::addScalingAlgorithmRow();

  addLayout(settingsLayout);
  setWindowTitle("Render Statistics Settings");
  resize(QSize(RS_SETTINGS_DIALOG_WIDTH, 0).expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());
}

RenderStatisticsSettingsDialog::~RenderStatisticsSettingsDialog() {
  if (renderImageWidthInputBox != nullptr) {
    settingsLayout->removeWidget(renderImageWidthInputBox);
    delete renderImageWidthInputBox;
    renderImageWidthInputBox = nullptr;
  }

  if (renderImageWidthLabel != nullptr) {
    settingsLayout->removeWidget(renderImageWidthLabel);
    delete renderImageWidthLabel;
    renderImageWidthLabel = nullptr;
  }

  if (scalingAlgorithmComboBox != nullptr) {
    settingsLayout->removeWidget(scalingAlgorithmComboBox);
    delete scalingAlgorithmComboBox;
    scalingAlgorithmComboBox = nullptr;
  }

  if (scalingAlgorithmLabel != nullptr) {
    settingsLayout->removeWidget(scalingAlgorithmLabel);
    delete scalingAlgorithmLabel;
    scalingAlgorithmLabel = nullptr;
  }

  if (settingsLayout != nullptr) {
    delete settingsLayout;
    settingsLayout = nullptr;
  }
}

void RenderStatisticsSettingsDialog::addRenderImageWidthRow() {
  renderImageWidthLabel = new QLabel("Render Image Width", this);
  renderImageWidthLabel->setObjectName("RenderImageWidthLabel");

  renderImageWidthInputBox = new QSpinBox(this);
  renderImageWidthInputBox->setObjectName("RenderImageWidthInputBox");
  renderImageWidthInputBox->setMinimum(RS_RENDER_IMAGE_DIALOG_MIN_WIDTH);
  renderImageWidthInputBox->setMaximum(RS_RENDER_IMAGE_DIALOG_MAX_WIDTH);
  renderImageWidthInputBox->setValue(settings->getRenderImageWidth());
  renderImageWidthInputBox->setToolTip(
    QString("The value must be between %1 and %2.").arg(
      QString::number(RS_RENDER_IMAGE_DIALOG_MIN_WIDTH),
      QString::number(RS_RENDER_IMAGE_DIALOG_MAX_WIDTH)
    )
  );

  settingsLayout->addRow(renderImageWidthLabel, renderImageWidthInputBox);
}

void RenderStatisticsSettingsDialog::addScalingAlgorithmRow() {
  scalingAlgorithmLabel = new QLabel("Scaling Algorithm", this);
  scalingAlgorithmLabel->setObjectName("ScalingAlgorithmLabel");

  scalingAlgorithmComboBox = new QComboBox(this);
  scalingAlgorithmComboBox->setObjectName("ScalingAlgorithmComboBox");
  scalingAlgorithmComboBox->insertItems(0, settings->getScalingAlgorithms());
  scalingAlgorithmComboBox->setCurrentIndex(settings->getScalingAlgorithm());

  settingsLayout->addRow(scalingAlgorithmLabel, scalingAlgorithmComboBox);
}
