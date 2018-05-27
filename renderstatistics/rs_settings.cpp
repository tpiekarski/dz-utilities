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

#include "rs_constants.h"
#include "rs_settings.h"
#include <dzapp.h>

RenderStatisticsSettings::RenderStatisticsSettings(RenderStatisticsLogger* logger) {
  setObjectName("RenderStatisticsSettings");
  this->logger = logger;
  settings = new DzAppSettings(RS_SETTINGS_PATH);
  loadRenderImageWidth();

  connect(dzApp, SIGNAL(closing()), this, SLOT(saveRenderImageWidth()));
}

RenderStatisticsSettings::~RenderStatisticsSettings() {
  if (settings != nullptr) {
    delete settings;
    settings = nullptr;
  }
}

void RenderStatisticsSettings::setRenderImageWidth(const int renderImageWidth) {
  this->renderImageWidth = renderImageWidth;
}

void RenderStatisticsSettings::saveRenderImageWidth() {
  settings->setIntValue(RS_SETTINGS_RENDERIMAGE_WIDTH_KEY, renderImageWidth);
}

void RenderStatisticsSettings::loadRenderImageWidth() {
  bool readSuccess = false;
  int storedRenderImageWidth = settings->getIntValue(
    RS_SETTINGS_RENDERIMAGE_WIDTH_KEY, RS_RENDER_IMAGE_DIALOG_DEFAULT_WIDTH, &readSuccess
  );

  if (readSuccess && validateRenderImageWidth(storedRenderImageWidth)) {
    renderImageWidth = storedRenderImageWidth;
  } else {
    logger->log(RS_SETTINGS_RENDERIMAGE_WIDTH_READING_FAILED_MSG);
    renderImageWidth = RS_RENDER_IMAGE_DIALOG_DEFAULT_WIDTH;
  }
}

bool RenderStatisticsSettings::validateRenderImageWidth(int newRenderImageWidth) {
  return newRenderImageWidth >= RS_RENDER_IMAGE_DIALOG_MIN_WIDTH && newRenderImageWidth <= RS_RENDER_IMAGE_DIALOG_MAX_WIDTH;
}
