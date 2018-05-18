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

#ifndef H_RENDERSTATISTICS_DZSTATISTICS
#define H_RENDERSTATISTICS_DZSTATISTICS

#include "rs_logger.h"
#include "rs_statistics.h"
#include <dzbasiccamera.h>
#include <dzcamera.h>

class DzRenderStatistics : public RenderStatistics {

public:
  DzRenderStatistics(
    const QString engine, const int nodes, DzCamera* camera, RenderStatisticsLogger* logger
  );

  ~DzRenderStatistics() = default;

  DzBasicCamera* getCamera() { return camera; }

private:
  RenderStatisticsLogger* logger;
  DzBasicCamera* camera;

};

#endif
