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

#ifndef PRECIMENT_SETTINGS_DIALOG_H
#define PRECIMENT_SETTINGS_DIALOG_H

#include "preciment_settings.h"
#include <dzbasicdialog.h>
#include <QtGui/qboxlayout.h>
#include <QtGui/qformlayout.h>
#include <QtGui/qgroupbox.h>
#include <QtGui/qlabel.h>
#include <QtGui/qlineedit.h>
#include <QtGui/qpushbutton.h>
#include <QtGui/qwidget.h>

class PrecimentControlDialog : public DzBasicDialog {

  Q_OBJECT

public:
  PrecimentControlDialog(QWidget* parent, PrecimentSettings* settings);
  ~PrecimentControlDialog();

private:
  PrecimentSettings* m_settings;

  QWidget* m_layoutWidget;
  QVBoxLayout* m_dialogLayout;
  QGroupBox* m_presetBox;
  QHBoxLayout* m_presetBoxLayout;
  QPushButton* m_presetButtonFine;
  QPushButton* m_presetButtonNormal;
  QPushButton* m_presetButtonRough;
  QGroupBox* m_multiplierBox;
  QFormLayout* m_multiplierFormLayout;
  QLabel* m_multiplierLabel;
  QLineEdit* m_multiplierLineEdit;

  QGroupBox* buildPresetBox();
  QGroupBox* buildMultiplierBox();
};

#endif