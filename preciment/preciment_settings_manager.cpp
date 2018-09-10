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

#include "preciment_settings_manager.h"
#include <QtCore/qlist.h>
#include <vector>

PrecimentSettingsManager::PrecimentSettingsManager(QObject* parent) 
  : QObject(parent), m_dzAppsettings(new DzAppSettings(QString::fromLatin1(PRECIMENT_SETTINGS_PATH))) 
{
  m_settings = PrecimentSettingsManager::load();
  m_keys << "positionXMultiplier" << "positionYMultiplier" << "positionZMultiplier"
    << "rotationXMultiplier" << "rotationYMultiplier" << "rotationZMultiplier"
    << "scaleXMultiplier" << "scaleYMultiplier" << "scaleZMultiplier";
}

PrecimentSettingsManager::~PrecimentSettingsManager() {
  PrecimentSettingsManager::save(m_settings);
}

void PrecimentSettingsManager::save(const PrecimentSettings settings) {
  for (int n = 0, key = 0; key < 9; ++key) {
    const PrecimentSettings::COORDINATE coordinate = static_cast<PrecimentSettings::COORDINATE>(n);
    m_dzAppsettings->setFloatValue(m_keys.at(key), static_cast<double>(settings.getPositionMultiplier(coordinate)));
    (n < 2) ? ++n : n = 0;
  }
}

PrecimentSettings PrecimentSettingsManager::load() {
  using std::vector;
  vector<float> values(m_keys.size(), PRECIMENT_FALLBACK_VALUE);

  for (int n = 0; n < values.size(); ++n) {
    values[n] = static_cast<float>(m_dzAppsettings->getFloatValue(m_keys.at(n), PRECIMENT_FALLBACK_VALUE));
  }

  const vector<float>::iterator p = values.begin();
  return PrecimentSettings(vector<float>(p, p + 3), vector<float>(p + 3, p + 6), vector<float>(p + 6, p + 9));
}
