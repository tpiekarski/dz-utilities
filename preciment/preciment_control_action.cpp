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

#include "preciment_version.h"
#include "preciment_control_action.h"
#include <dzapp.h>

PrecimentControlAction::~PrecimentControlAction() {
  if (m_dialog != nullptr) {
    delete m_dialog;
    m_dialog = nullptr;
  }

  if (m_settings != nullptr) {
    delete m_settings;
    m_settings = nullptr;
  }
}

void PrecimentControlAction::executeAction() {
  // todo: implement logic for handling dialog and settings

  m_dialog->exec();
}
