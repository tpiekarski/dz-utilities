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

#include "console_search_pane.h"
#include <dzapp.h>
#include <QtCore/qstring.h>
#include <QtGui/qtextcursor.h>
#include <QtGui/qtextformat.h>

ConsoleSearchPane::ConsoleSearchPane(ConsoleLogBrowser* logBrowser) {
  this->logBrowser = logBrowser;
  this->document = logBrowser->getDocument();
  startover = true;

  searchEditBox = new QLineEdit();
  searchButton = new QPushButton("&Search");
  highlightButton = new QPushButton("&Highlight");
  highlightButton->setCheckable(true);
  resetButton = new QPushButton("&Reset");
  resetButton->setVisible(false);

  highlightFormat = new QTextCharFormat(*logBrowser->getCurrentCharacterFormat());

  layout = new QHBoxLayout();
  layout->addWidget(searchEditBox);
  layout->addWidget(searchButton);
  layout->addWidget(highlightButton);
  layout->addWidget(resetButton);

  connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));
  connect(highlightButton, SIGNAL(clicked()), this, SLOT(highlight()));
  connect(this, SIGNAL(resetButtonToDisplay(const bool&)), this, SLOT(toggleResetButton(const bool&)));
  connect(resetButton, SIGNAL(clicked()), this, SLOT(reset()));
}

ConsoleSearchPane::~ConsoleSearchPane() {
  if (searchEditBox != nullptr) {
    delete searchEditBox;
    searchEditBox = nullptr;
  }

  if (searchButton != nullptr) {
    delete searchButton;
    searchButton = nullptr;
  }

  if (highlightButton != nullptr) {
    delete highlightButton;
    highlightButton = nullptr;
  }

  if (resetButton != nullptr) {
    delete resetButton;
    resetButton = nullptr;
  }

  if (highlightFormat != nullptr) {
    delete highlightFormat;
    highlightFormat = nullptr;
  }

  if (layout != nullptr) {
    delete layout;
    layout = nullptr;
  }
}

void ConsoleSearchPane::search() {
  const QString searchTerm = searchEditBox->text();

  if (searchTerm.isEmpty()) {
    return;
  }

  emit resetButtonToDisplay(true);

  if (startover) {
    logBrowser->moveCursor(QTextCursor::Start);
  }

  startover = !logBrowser->find(searchTerm);
}

void ConsoleSearchPane::highlight() {
  const QString searchTerm = searchEditBox->text();

  if (searchTerm.isEmpty()) {
    return;
  }

  emit resetButtonToDisplay(true);
  updateHighlightFormat();

  if (highlight(searchTerm, highlightFormat)) {
    searchEditBox->setReadOnly(true);
    highlightButton->setChecked(true);
    disconnect(highlightButton, SIGNAL(clicked()), NULL, NULL);
    connect(highlightButton, SIGNAL(clicked()), this, SLOT(unhighlight()));
    disconnect(logBrowser, SIGNAL(logCleared()), NULL, NULL);
    connect(logBrowser, SIGNAL(logCleared()), this, SLOT(unhighlight()));
    disconnect(logBrowser, SIGNAL(logReloaded()), NULL, NULL);
    connect(logBrowser, SIGNAL(logReloaded()), this, SLOT(highlight()));
  } else {
    highlightButton->setChecked(false);
  }
}

void ConsoleSearchPane::unhighlight() {
  highlight(searchEditBox->text(), logBrowser->getCurrentCharacterFormat());
  searchEditBox->setReadOnly(false);
  highlightButton->setChecked(false);
  disconnect(highlightButton, SIGNAL(clicked()), NULL, NULL);
  connect(highlightButton, SIGNAL(clicked()), this, SLOT(highlight()));
  disconnect(logBrowser, SIGNAL(logCleared()), NULL, NULL);
  disconnect(logBrowser, SIGNAL(logReloaded()), NULL, NULL);
}

bool ConsoleSearchPane::highlight(const QString searchTerm, QTextCharFormat* highlightFormat) {
  QTextCursor highlightCursor(document);
  bool highlighted = false;

  while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
    highlightCursor = document->find(searchTerm, highlightCursor, QTextDocument::FindWholeWords);

    if (!highlightCursor.isNull()) {
      highlightCursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
      highlightCursor.setCharFormat(*highlightFormat);

      if (!highlighted) {
        highlighted = true;
      }
    }
  }

  return highlighted;
}

void ConsoleSearchPane::reset() {
  searchEditBox->clear();
  unhighlight();
  logBrowser->reloadLog();
  emit resetButtonToDisplay(false);
}

void ConsoleSearchPane::updateHighlightFormat() {
  float fontSize = NULL;
  logBrowser->getSettings()->getFontSize(&fontSize);
  highlightFormat->setFontPointSize(fontSize);
  highlightFormat->clearForeground();
  highlightFormat->setForeground(QBrush(logBrowser->getSettings()->getHighlightColor()));
}

void ConsoleSearchPane::toggleResetButton(const bool& visibility) {
  if (resetButton->isVisible() != visibility) {
    resetButton->setVisible(visibility);
  }
}
