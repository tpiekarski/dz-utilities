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
#include <QtGui/qlabel.h>
#include <QtGui/qlineedit.h>

/*
 * Class: ConsolePropertiesDialog
 * Description: Dialog for setting up properties like font size.
 *
 */
class ConsolePropertiesDialog : public DzBasicDialog {

  Q_OBJECT

public:
  ConsolePropertiesDialog(QWidget* parent, ConsoleSettings* settings);
  ~ConsolePropertiesDialog();

  QString getNewFontSize();

private:
  QLabel* fontSizeLabel;
  QLineEdit* fontSizeEditBox;
  QLabel* logFilePathLabel;
  QLineEdit* logFilePathDisplayBox;

};

#endif
