/*
* Project:   dzUtilities::RenderStatistics
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#ifndef H_RENDERSTATISTICS_SETTINGS
#define H_RENDERSTATISTICS_SETTINGS

#include "rs_logger.h"
#include <dzappsettings.h>
#include <QtCore/qobject.h>
#include <QtCore/qstringlist.h>

class RenderStatisticsSettings : public QObject {

  Q_OBJECT

public:
  RenderStatisticsSettings(RenderStatisticsLogger* logger);
  ~RenderStatisticsSettings();

  int getRenderImageWidth() { return renderImageWidth; };
  void setRenderImageWidth(const int renderImageWidth);
  QStringList getScalingAlgorithms() { return scalingAlgorithms; };
  Qt::TransformationMode getScalingAlgorithm() { return scalingAlgorithm; };
  void setScalingAlgorithm(const QString scalingAlgorithm);

private slots:
  void saveRenderImageWidth();

private:
  RenderStatisticsLogger* logger;
  DzAppSettings* settings;
  int renderImageWidth;
  QStringList scalingAlgorithms;
  Qt::TransformationMode scalingAlgorithm;

  void loadRenderImageWidth();
  bool validateRenderImageWidth(int newRenderImageWidth);

};
#endif
