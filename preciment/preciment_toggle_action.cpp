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
#include "preciment_toggle_action.h"
#include <dzapp.h>
#include <dznode.h>
#include <dzscene.h>
#include <QtCore/qobject.h>

PrecimentToggleAction::PrecimentToggleAction() 
  : DzEditAction("Preciment/Toggle", "Toggle precise adjustments"), 
    m_settings(), 
    m_modifier(this), 
    m_toggle(PrecimentSettings::INITIAL_TOGGLE) {}

PrecimentToggleAction::~PrecimentToggleAction() {}

void PrecimentToggleAction::executeAction() {
  dzApp->log(QString("Preciment: Multipliers\nPosition (X/Y/Z): %1, Rotation (X/Y/Z): %2, Scale (X/Y/Z): %3").arg(
    m_settings.getPositionMultiplierString(), m_settings.getRotationMultiplierString(), m_settings.getScaleMultiplierString()
  ));
  
  if (dzScene->getSelectedNodeList().count() == 0) {
    dzApp->log("Preciment: There are no nodes selected.");

    return;
  }

  m_modifier.modify(dzScene->selectedNodeListIterator(), m_settings, toggle());
}

bool PrecimentToggleAction::toggle() {
  m_toggle = !m_toggle;

  return m_toggle;
}
