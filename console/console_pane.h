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

#ifndef H_CONSOLE_PANE
#define H_CONSOLE_PANE

#include "console.h"
#include "console_log_browser.h"
#include "console_search_pane.h"
#include "console_settings.h"
#include <dzactionmenu.h>
#include <dzpane.h>
#include <QtGui/qboxlayout.h>

/*
 * Class: ConsolePane
 * Description: Main class for the console pane.
 */
class ConsolePane : public DzPane {

  Q_OBJECT

public:
  ConsolePane();
  ~ConsolePane();

  ConsoleLogBrowser* getConsoleLogBrowser() { return consoleLogBrowser; };
  void showProperties();

protected:
  void buildOptionsMenu(DzActionMenu* menu) const override;

private:
  Console* console;
  ConsoleLogBrowser* consoleLogBrowser;
  ConsoleSearchPane* consoleSearchPane;
  ConsoleSettings* consoleSettings;
  QVBoxLayout* paneMainLayout;
  
};

#endif
