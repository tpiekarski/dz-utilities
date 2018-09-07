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

class PrecimentPropertyModifier : public QObject {

  Q_OBJECT

public:
  explicit PrecimentPropertyModifier(QObject* parent) : QObject(parent) {}
  PrecimentPropertyModifier(const PrecimentPropertyModifier&) = default;
  PrecimentPropertyModifier(PrecimentPropertyModifier&&) = default;
  ~PrecimentPropertyModifier() = default;

  void modify(DzNodeListIterator& nodeIterator, const PrecimentSettings& settings);

private:
  void modifyPosition(DzNode* node, const PrecimentSettings& settings);
  void modifyRotation(DzNode* node, const PrecimentSettings& settings);
  void modifyScale(DzNode* node, const PrecimentSettings& settings);
  float multiply(DzFloatProperty* property, float value);

};

#endif