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

#ifndef H_CONSOLE_LOG_BROWSER
#define H_CONSOLE_LOG_BROWSER

#include "console.h"
#include "console_settings.h"
#include <QtCore/qobject.h>
#include <QtGui/qboxlayout.h>
#include <QtGui/qtextcursor.h>
#include <QtGui/qtextbrowser.h>

class ConsoleLogBrowser : public QObject {

  Q_OBJECT

public:
  ConsoleLogBrowser(Console* console, ConsoleSettings* settings);
  ~ConsoleLogBrowser();

  QHBoxLayout* getLayout() { return layout; };
  QTextBrowser* getBrowser() { return browser; };
  void clearLog();

public slots:
  void openLog();
  void updateLog();
  void reloadLog();

private:
  bool logWatched;
  Console* console;
  ConsoleSettings* settings;
  QHBoxLayout* layout;
  QTextBrowser* browser;

  void moveCursor(const QTextCursor::MoveOperation position);
};
#endif
