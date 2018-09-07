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

#ifndef PRECIMENT_SETTINGS_H
#define PRECIMENT_SETTINGS_H

#include <QtCore\qstring.h>
#include <vector>

using std::vector;

class PrecimentSettings {

public:
  PrecimentSettings()
    : m_positionMultipliers(3, DEFAULT_MULTIPLIER), 
      m_rotationMultipliers(3, DEFAULT_MULTIPLIER), 
      m_scaleMultipliers(3, DEFAULT_MULTIPLIER) { }

  PrecimentSettings(vector<float> positionMultipliers, vector<float> rotationMultipliers, vector<float> scaleMultipliers)
    : m_positionMultipliers(positionMultipliers), 
      m_rotationMultipliers(rotationMultipliers), 
      m_scaleMultipliers(scaleMultipliers) { }

  enum COORDINATE {
    X = 0,
    Y = 1,
    Z = 2
  };

  float getPositionMultiplier(const COORDINATE coordinate) const { return m_positionMultipliers[coordinate]; }
  float getRotationMultiplier(const COORDINATE coordinate) const { return m_rotationMultipliers[coordinate]; }
  float getScaleMultiplier(const COORDINATE coordinate) const { return m_scaleMultipliers[coordinate]; }

  QString getPositionMultiplierString();
  QString getRotationMultiplierString();
  QString getScaleMultiplierString();

private:
  static constexpr float DEFAULT_MULTIPLIER = 0.1f;
  static constexpr char DEFAULT_COORDINATE_FORMAT[] = "%1/%2/%3";

  vector<float> m_positionMultipliers;
  vector<float> m_rotationMultipliers;
  vector<float> m_scaleMultipliers;

};

#endif
