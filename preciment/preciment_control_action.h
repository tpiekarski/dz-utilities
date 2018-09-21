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

#ifndef PRECIMENT_CONTROL_ACTION_H
#define PRECIMENT_CONTROL_ACTION_H

#include "preciment_control_dialog.h"
#include "preciment_settings_manager.h"
#include <dzaction.h>

class PrecimentControlAction : public DzEditAction {

  Q_OBJECT

public:
  PrecimentControlAction()
    : DzEditAction("Preciment/Control", "Control offsets for precise adjustments"),
      m_manager(new PrecimentSettingsManager(this)),
      m_dialog(new PrecimentControlDialog(nullptr, m_manager)) { }

  ~PrecimentControlAction();

signals:
  void settingsChanged(const PrecimentSettings& settings);

protected:
  virtual void executeAction();

private:
  PrecimentSettingsManager* m_manager;
  PrecimentControlDialog* m_dialog;

};

#endif

