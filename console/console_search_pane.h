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
#include <QtCore/qobject.h>
#include <QtCore/qstring.h>
#include <QtGui/qboxlayout.h>
#include <QtGui/qlineedit.h>
#include <QtGui/qpushbutton.h>
#include <QtGui/qtextdocument.h>
#include <QtGui/qtextformat.h>

class ConsoleSearchPane : public QObject {

  Q_OBJECT

public:
  ConsoleSearchPane(ConsoleLogBrowser* logBrowser);
  ~ConsoleSearchPane();

  QHBoxLayout* getLayout() { return layout; };

private slots:
  void highlight();
  void unhighlight();
  void search();
  void toggleResetButton(const bool& visibility);
  void reset();

signals:
  void resetButtonToDisplay(const bool& visibility);

private:
  bool startover;
  ConsoleLogBrowser* logBrowser;
  QHBoxLayout* layout;
  QLineEdit* searchEditBox;
  QPushButton* highlightButton;
  QPushButton* searchButton;
  QPushButton* resetButton;
  QTextCharFormat* highlightFormat;
  QTextDocument* document;

  bool highlight(const QString searchTerm, QTextCharFormat* highlightFormat);
  void updateHighlightFormat();

};
#endif

