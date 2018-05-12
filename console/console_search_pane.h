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

#ifndef H_CONSOLE_SEARCH_PANE
#define H_CONSOLE_SEARCH_PANE

#include "console_log_browser.h"
#include <QtGui/qboxlayout.h>
#include <QtGui/qlineedit.h>
#include <QtGui/qpushbutton.h>

class ConsoleSearchPane {

public:
  ConsoleSearchPane(ConsoleLogBrowser* logBrowser);
  ~ConsoleSearchPane();

  QHBoxLayout* getLayout() { return layout; };

private:
  ConsoleLogBrowser* logBrowser;
  QHBoxLayout* layout;
  QLineEdit* searchEditBox;
  QPushButton* searchButton;

};
#endif

