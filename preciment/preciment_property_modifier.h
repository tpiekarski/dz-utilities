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

#ifndef PRECIMENT_PROPERTY_MODIFIER_H
#define PRECIMENT_PROPERTY_MODIFIER_H

#include "preciment_settings.h"
#include <dznode.h>
#include <dzfloatproperty.h>
#include <QtCore/qobject.h>
#include <vector>

using std::vector;

class PrecimentPropertyModifier : public QObject {

  Q_OBJECT

public:
  explicit PrecimentPropertyModifier(QObject* parent) : QObject(parent), m_toggle(PrecimentSettings::INITIAL_TOGGLE) {}
  PrecimentPropertyModifier(const PrecimentPropertyModifier&) = default;
  PrecimentPropertyModifier(PrecimentPropertyModifier&&) = default;
  ~PrecimentPropertyModifier() = default;

  void modify(DzNodeListIterator& nodeIterator, const PrecimentSettings& settings, const bool& toggle);

private:
  void modifyPosition(DzNode* node, const vector<float> position);
  void modifyRotation(DzNode* node, const vector<float> rotation);
  void modifyScale(DzNode* node, const vector<float> scale);

  float modify(DzFloatProperty* property, float value);

  bool m_toggle;
};

#endif