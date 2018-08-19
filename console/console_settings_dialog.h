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

#ifndef H_CONSOLE_PROPERTIES_DIALOG
#define H_CONSOLE_PROPERTIES_DIALOG

#include "console_settings.h"
#include <dzbasicdialog.h>
#include <QtCore/qstring.h>
#include <QtGui/qcolor.h>
#include <QtGui/qformlayout.h>
#include <QtGui/qlabel.h>
#include <QtGui/qlineedit.h>
#include <QtGui/qspinbox.h>

class ConsoleSettingsDialog : public DzBasicDialog {

  Q_OBJECT

public:
  ConsoleSettingsDialog(QWidget* parent, ConsoleSettings* settings);
  ~ConsoleSettingsDialog();

  QString getNewFontSize() { return fontSizeSpinBox->text(); };
  QColor getNewHighlightColor() { return newHighlightColor; };

private slots:
  void selectHighlightColor();

private:
  ConsoleSettings* settings;
  QFormLayout* formLayout;
  QWidget* formWidget;
  QLabel* logFilePathLabel;
  QLineEdit* logFilePathDisplayBox;
  QLabel* fontSizeLabel;
  QSpinBox* fontSizeSpinBox;
  QLabel* highlightColorLabel;
  QColor newHighlightColor;
  QPushButton* highlightColorButton;

  void addFilePathRow();
  void addFontSizeRow();
  void addHighlightColorRow();

};

#endif
