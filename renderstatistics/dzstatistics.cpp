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

#include "dzstatistics.h"
#include <QtCore/qstring.h>

DzRenderStatistics::DzRenderStatistics(
  const QString engine, const int nodes, DzCamera* camera, RenderStatisticsLogger* logger
) : RenderStatistics(engine.toStdString(), nodes)
{
  this->logger = logger;

  if (camera->inherits("DzBasicCamera")) {
    this->camera = dynamic_cast<DzBasicCamera*>(camera);
    logger->log(
      QString("Saving reference to camera %1.").arg(this->camera->getName())
    );
  } else {
    this->camera = nullptr;
    logger->log(
      QString("Can not cast the camera %1 to DzBasicCamera. No reference will be saved.").arg(camera->getName())
    );
  }

}
