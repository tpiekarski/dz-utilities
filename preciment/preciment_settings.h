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
  enum COORDINATE { X = 0, Y = 1, Z = 2 };
  static constexpr float DEFAULT_MULTIPLIER = 0.1f;
  static constexpr bool INITIAL_TOGGLE = false;

  PrecimentSettings()
    : m_singleMultiplier(DEFAULT_MULTIPLIER),
      m_positionMultipliers(3, DEFAULT_MULTIPLIER),
      m_rotationMultipliers(3, DEFAULT_MULTIPLIER),
      m_scaleMultipliers(3, DEFAULT_MULTIPLIER) { }

  PrecimentSettings(
    float singleMultiplier,
    vector<float> positionMultipliers,
    vector<float> rotationMultipliers,
    vector<float> scaleMultipliers
  ) : m_singleMultiplier(singleMultiplier),
      m_positionMultipliers(positionMultipliers),
      m_rotationMultipliers(rotationMultipliers),
      m_scaleMultipliers(scaleMultipliers) { }

  bool operator==(const PrecimentSettings& other) { return this->compare(other); }
  bool operator!=(const PrecimentSettings& other) { return this->compare(other); }

  void setSingleMultiplier(float singleMultiplier) { m_singleMultiplier = singleMultiplier; }
  float getSingleMultiplier() const { return m_singleMultiplier; }

  vector<float> getPositionMultiplier() const { return m_positionMultipliers; }
  vector<float> getRotationMultiplier() const { return m_rotationMultipliers; }
  vector<float> getScaleMultiplier() const { return m_scaleMultipliers; }

  float getPositionMultiplier(const COORDINATE coordinate) const { return m_positionMultipliers[coordinate]; }
  float getRotationMultiplier(const COORDINATE coordinate) const { return m_rotationMultipliers[coordinate]; }
  float getScaleMultiplier(const COORDINATE coordinate) const { return m_scaleMultipliers[coordinate]; }

  QString getSingleMultiplierString();
  QString getPositionMultiplierString();
  QString getRotationMultiplierString();
  QString getScaleMultiplierString();

private:
  static constexpr char DEFAULT_COORDINATE_FORMAT[] = "%1/%2/%3";

  float m_singleMultiplier;
  vector<float> m_positionMultipliers;
  vector<float> m_rotationMultipliers;
  vector<float> m_scaleMultipliers;

  bool compare(const PrecimentSettings& other);

};

#endif
