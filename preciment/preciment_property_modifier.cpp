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

#include "preciment_property_modifier.h"
#include <dzApp.h>

void PrecimentPropertyModifier::modify(DzNodeListIterator& nodeIterator, const PrecimentSettings& settings, const bool& toggle) {
  dzApp->log(QString("Preciment: Modyfing (%1)").arg(toggle));
  m_toggle = toggle;

  DzNode* currentNode = nullptr;
  while (nodeIterator.hasNext()) {
    currentNode = nodeIterator.next();
    modifyPosition(currentNode, settings.getPositionMultiplier());
    modifyRotation(currentNode, settings.getRotationMultiplier());
    modifyScale(currentNode, settings.getScaleMultiplier());
  }
}

void PrecimentPropertyModifier::modifyPosition(DzNode* node, const vector<float> position) {
  node->getXPosControl()->setSensitivity(modify(node->getXPosControl(), position.at(PrecimentSettings::COORDINATE::X)));
  node->getYPosControl()->setSensitivity(modify(node->getYPosControl(), position.at(PrecimentSettings::COORDINATE::Y)));
  node->getZPosControl()->setSensitivity(modify(node->getZPosControl(), position.at(PrecimentSettings::COORDINATE::Z)));
}

void PrecimentPropertyModifier::modifyRotation(DzNode* node, const vector<float> rotation) {
  node->getXRotControl()->setSensitivity(modify(node->getXRotControl(), rotation.at(PrecimentSettings::COORDINATE::X)));
  node->getYRotControl()->setSensitivity(modify(node->getYRotControl(), rotation.at(PrecimentSettings::COORDINATE::Y)));
  node->getZRotControl()->setSensitivity(modify(node->getZRotControl(), rotation.at(PrecimentSettings::COORDINATE::Z)));
}

void PrecimentPropertyModifier::modifyScale(DzNode* node, const vector<float> scale) {
  node->getXScaleControl()->setSensitivity(modify(node->getXScaleControl(), scale.at(PrecimentSettings::COORDINATE::X)));
  node->getYScaleControl()->setSensitivity(modify(node->getYScaleControl(), scale.at(PrecimentSettings::COORDINATE::Y)));
  node->getZScaleControl()->setSensitivity(modify(node->getZScaleControl(), scale.at(PrecimentSettings::COORDINATE::Z)));
}

float PrecimentPropertyModifier::modify(DzFloatProperty * currentProperty, const float value) {
  return (m_toggle) ? currentProperty->getSensitivity() * value : currentProperty->getSensitivity() / value;
}
