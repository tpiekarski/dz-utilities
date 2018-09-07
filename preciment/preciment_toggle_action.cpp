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
  : DzEditAction("Preciment/Toggle", "Toggle precise adjustments"), m_settings(), m_modifier(this) {}

PrecimentToggleAction::~PrecimentToggleAction() {}

void PrecimentToggleAction::executeAction() {
  dzApp->log(QString("Preciment multipliers:\nPosition (X/Y/Z): %1\nRotation (X/Y/Z): %2\nScale (X/Y/Z): %3").arg(
    m_settings.getPositionMultiplierString(), m_settings.getRotationMultiplierString(), m_settings.getScaleMultiplierString()
  ));
  
  if (dzScene->getSelectedNodeList().count() == 0) {
    dzApp->log("Preciment: There are no nodes selected.");

    return;
  }

  DzNodeListIterator nodeIterator = dzScene->selectedNodeListIterator();
  m_modifier.modify(nodeIterator, m_settings);

}
