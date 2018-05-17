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

#ifndef H_RENDERSTATISTICS_QRENDERIMAGEBUTTON
#define H_RENDERSTATISTICS_QRENDERIMAGEBUTTON

#include "logger.h"
#include <QtGui/qpushbutton.h>

class QRenderImageButton : public QPushButton {

  Q_OBJECT

public:
  QRenderImageButton(const QString iconFullPath, RenderStatisticsLogger* logger);
  ~QRenderImageButton();

private:
  QIcon* icon;
  QPixmap* pixmap;
  QSize* iconSize;
  QSize* buttonSize;
};

#endif