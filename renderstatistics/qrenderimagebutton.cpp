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

#include "qrenderimagebutton.h"
#include <QtCore/qfile.h>

QRenderImageButton::QRenderImageButton(const QString iconFullPath, RenderStatisticsLogger* logger) {
  QFile* iconFile = new QFile(iconFullPath);

  if (iconFile->open(QIODevice::ReadOnly)) {
    pixmap = new QPixmap(iconFullPath);
    icon = new QIcon(*pixmap);
    iconSize = new QSize(pixmap->width(), pixmap->height());
    buttonSize = new QSize(
      iconSize->width() + DEFAULT_RENDERIMAGE_BUTTON_BORDER,
      iconSize->height() + DEFAULT_RENDERIMAGE_BUTTON_BORDER
    );

    setIcon(*icon);
    setIconSize(*iconSize);
    setMinimumSize(*buttonSize);
    setMaximumSize(*buttonSize);
  } else {
    logger->log(QString("Failed to open icon file (%1) for render image button.").arg(iconFullPath));

    pixmap = nullptr;
    icon = nullptr;
    iconSize = nullptr;
    buttonSize = nullptr;

    setText("Image");
  }

  if (iconFile->isOpen()) {
    iconFile->close();
  }

  if (iconFile != nullptr) {
    delete(iconFile);
    iconFile = nullptr;
  }
}

QRenderImageButton::~QRenderImageButton() {
  if (buttonSize != nullptr) {
    delete(buttonSize);
    buttonSize = nullptr;
  }

  if (iconSize != nullptr) {
    delete(iconSize);
    iconSize = nullptr;
  }

  if (icon != nullptr) {
    delete(icon);
    icon = nullptr;
  }

  if (pixmap != nullptr) {
    delete(pixmap);
    pixmap = nullptr;
  }

}


