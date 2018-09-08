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

#ifndef PRECIMENT_TOGGLE_ACTION_H
#define PRECIMENT_TOGGLE_ACTION_H

#include "preciment_property_modifier.h"
#include "preciment_settings.h"
#include <dzaction.h>

class PrecimentToggleAction : public DzEditAction {

  Q_OBJECT

public:
  PrecimentToggleAction();
  ~PrecimentToggleAction();

protected:
  virtual void executeAction();

private:
  bool toggle();
  PrecimentSettings m_settings;
  PrecimentPropertyModifier m_modifier;
  bool m_toggle;

};

#endif

