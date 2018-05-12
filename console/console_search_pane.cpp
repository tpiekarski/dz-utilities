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

ConsoleSearchPane::ConsoleSearchPane(ConsoleLogBrowser* logBrowser) {
  this->logBrowser = logBrowser;

  searchEditBox = new QLineEdit();
  searchButton = new QPushButton("&Search");
  
  layout = new QHBoxLayout();
  layout->addWidget(searchEditBox);
  layout->addWidget(searchButton);
}


ConsoleSearchPane::~ConsoleSearchPane() {
  if (searchEditBox != nullptr) {
    delete(searchEditBox);
    searchEditBox = nullptr;
  }

  if (searchButton != nullptr) {
    delete(searchButton);
    searchButton = nullptr;
  }

  if (layout != nullptr) {
    delete(layout);
    layout = nullptr;
  }
}
