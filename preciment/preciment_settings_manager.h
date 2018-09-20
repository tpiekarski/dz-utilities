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

#ifndef PRECIMENT_SETTINGS_MANAGER_H
#define PRECIMENT_SETTINGS_MANAGER_H

#include "preciment_settings.h"
#include <dzappsettings.h>
#include <QtCore/qobject.h>

class PrecimentSettingsManager : public QObject {

  Q_OBJECT

public:
  PrecimentSettingsManager(QObject* parent);
  ~PrecimentSettingsManager();

  PrecimentSettings getSettings() { return m_settings; }

public slots:
  void save(const PrecimentSettings settings);
  PrecimentSettings load();

private:
  static constexpr char PRECIMENT_SETTINGS_PATH[] = "Preciment";
  
  QList<QString> m_keys;
  PrecimentSettings m_settings;
  DzAppSettings* m_dzAppsettings;
};

#endif
