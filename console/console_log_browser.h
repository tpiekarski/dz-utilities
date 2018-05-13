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
#include <QtGui/qtextdocument.h>
#include <QtGui/qtextbrowser.h>
#include <QtGui/qtextformat.h>

class ConsoleLogBrowser : public QObject {

  Q_OBJECT

public:
  ConsoleLogBrowser(Console* console, ConsoleSettings* settings);
  ~ConsoleLogBrowser();

  QHBoxLayout* getLayout() { return layout; };
  QTextCharFormat* getCurrentCharacterFormat() { return currentCharacterFormat; };
  QTextDocument* getDocument() { return browser->document(); };
  QTextEdit* getBrowser() { return browser; };
  
  bool find(const QString searchTerm, const QTextDocument::FindFlags options = QTextDocument::FindWholeWords);
  void clearLog();
  void moveCursor(const QTextCursor::MoveOperation position);
  void updateFontSize(const QString newFontSize);

public slots:
  void openLog();
  void updateLog();
  void reloadLog();

signals:
  void logCleared();
  void logReloaded();

private:
  bool logWatched;
  Console* console;
  ConsoleSettings* settings;
  QHBoxLayout* layout;
  QTextEdit* browser;
  QTextCharFormat* currentCharacterFormat;

  void resetCharacterFormat();
};
#endif
