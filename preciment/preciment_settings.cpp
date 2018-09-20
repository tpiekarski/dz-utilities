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

#include "preciment_settings.h"

QString PrecimentSettings::getSingleMultiplierString() {
  return QString::number(getSingleMultiplier());
}

QString PrecimentSettings::getPositionMultiplierString() {
  return QString(QString::fromLatin1(DEFAULT_COORDINATE_FORMAT)).arg(
    QString::number(getPositionMultiplier(COORDINATE::X)),
    QString::number(getPositionMultiplier(COORDINATE::Y)),
    QString::number(getPositionMultiplier(COORDINATE::Z))
  );
}

QString PrecimentSettings::getRotationMultiplierString() {
  return QString(QString::fromLatin1(DEFAULT_COORDINATE_FORMAT)).arg(
    QString::number(getRotationMultiplier(COORDINATE::X)),
    QString::number(getRotationMultiplier(COORDINATE::Y)),
    QString::number(getRotationMultiplier(COORDINATE::Z))
  );
}

QString PrecimentSettings::getScaleMultiplierString() {
  return QString(QString::fromLatin1(DEFAULT_COORDINATE_FORMAT)).arg(
    QString::number(getScaleMultiplier(COORDINATE::X)),
    QString::number(getScaleMultiplier(COORDINATE::Y)),
    QString::number(getScaleMultiplier(COORDINATE::Z))
  );
}
