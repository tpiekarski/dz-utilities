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
#include <QtGui/qlayout.h>

RenderStatisticsSettingsDialog::RenderStatisticsSettingsDialog(
  QWidget* parent, RenderStatisticsSettings* settings
) : DzBasicDialog(parent, "RenderStatisticsSettings") 
{
  this->settings = settings;
  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  layout()->setMargin(margin);
  layout()->setSpacing(margin);
  layout()->setSizeConstraint(QLayout::SetNoConstraint);

  renderImageWidthLabel = new QLabel("Render Image Width", this);
  renderImageWidthLabel->setObjectName("RenderImageWidthLabel");
  renderImageWidthLabel->setBuddy(renderImageWidthInput);
  addWidget(renderImageWidthLabel);

  QString newRenderImageWidth = NULL;
  renderImageWidthInput = new QLineEdit(newRenderImageWidth, this);
  renderImageWidthInput->setObjectName("RenderImageWidthInput");
  addWidget(renderImageWidthInput);

  setWindowTitle("Render Statistics Settings");
  resize(QSize(SETTINGS_DIALOG_WIDTH, 0).expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());

}

RenderStatisticsSettingsDialog::~RenderStatisticsSettingsDialog() {
  if (renderImageWidthInput != nullptr) {
    delete(renderImageWidthInput);
    renderImageWidthInput = nullptr;
  }

  if (renderImageWidthLabel != nullptr) {
    delete(renderImageWidthLabel);
    renderImageWidthLabel = nullptr;
  }
}
