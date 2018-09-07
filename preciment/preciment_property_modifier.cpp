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

void PrecimentPropertyModifier::modify(DzNodeListIterator& nodeIterator, const PrecimentSettings& settings) {
  dzApp->log("Preciment: Modyfing...");
  DzNode* currentNode = nullptr;

  while (nodeIterator.hasNext()) {
    currentNode = nodeIterator.next();
    modifyPosition(currentNode, settings);
    modifyRotation(currentNode, settings);
    modifyScale(currentNode, settings);
  }

}

void PrecimentPropertyModifier::modifyPosition(DzNode* node, const PrecimentSettings& settings) {
  node->getXPosControl()->setSensitivity(multiply(
    node->getXPosControl(), settings.getPositionMultiplier(PrecimentSettings::COORDINATE::X)
  ));
  node->getYPosControl()->setSensitivity(multiply(
    node->getYPosControl(), settings.getPositionMultiplier(PrecimentSettings::COORDINATE::Y)
  ));
  node->getZPosControl()->setSensitivity(multiply(
    node->getZPosControl(), settings.getPositionMultiplier(PrecimentSettings::COORDINATE::Z)
  ));
}

void PrecimentPropertyModifier::modifyRotation(DzNode* node, const PrecimentSettings& settings) {
  node->getXRotControl()->setSensitivity(multiply(
    node->getXRotControl(), settings.getRotationMultiplier(PrecimentSettings::COORDINATE::X)
  ));
  node->getYRotControl()->setSensitivity(multiply(
    node->getYRotControl(), settings.getRotationMultiplier(PrecimentSettings::COORDINATE::Y)
  ));
  node->getZRotControl()->setSensitivity(multiply(
    node->getZRotControl(), settings.getRotationMultiplier(PrecimentSettings::COORDINATE::Z)
  ));
}

void PrecimentPropertyModifier::modifyScale(DzNode* node, const PrecimentSettings& settings) {
  node->getXScaleControl()->setSensitivity(multiply(
    node->getXScaleControl(), settings.getScaleMultiplier(PrecimentSettings::COORDINATE::X)
  ));
  node->getYScaleControl()->setSensitivity(multiply(
    node->getYScaleControl(), settings.getScaleMultiplier(PrecimentSettings::COORDINATE::Y)
  ));
  node->getZScaleControl()->setSensitivity(multiply(
    node->getZScaleControl(), settings.getScaleMultiplier(PrecimentSettings::COORDINATE::Z)
  ));
}

float PrecimentPropertyModifier::multiply(DzFloatProperty * currentProperty, const float value) {
  return currentProperty->getSensitivity() * value;
}
