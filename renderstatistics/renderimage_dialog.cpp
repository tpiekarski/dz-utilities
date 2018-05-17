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

#include "constants.h"
#include "renderimage_dialog.h"
#include <dzapp.h>
#include <QtGui/qfiledialog.h>
#include <QtGui/qlayout.h>

RenderImageDialog::RenderImageDialog(
  QWidget* parent, vector<DzRenderStatistics>* statistics, const int current, RenderStatisticsLogger* logger
) : DzBasicDialog(parent, "RenderImage") {

  this->statistics = statistics;
  this->current = current;
  this->logger = logger;
  this->dialogWidth = DEFAULT_DIALOG_WIDTH;

  RenderStatistics* currentStatistic = &statistics->at(current);
  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  const QString filePath = QString("%1/%2").arg(
    dzApp->getTempPath(), QString::fromStdString(currentStatistic->getRenderImage())
  );

  addWidget(buildRenderImageWidget(buildFullPath(currentStatistic->getRenderImage())));

  layout()->setMargin(margin);
  layout()->setSpacing(margin);
  layout()->setSizeConstraint(QLayout::SetNoConstraint);

  setWindowTitle("Render Image");
  resize(QSize(dialogWidth, 0).expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());

  showCancelButton(false);
  showHelpButton(false);
  addBrowseRenderImageButtons();
}

RenderImageDialog::~RenderImageDialog() {
  logger->log("Destructing render image dialog.");

  if (renderImage != nullptr) {
    delete(renderImage);
    renderImage = nullptr;

    if (renderImageWidget != nullptr) {
      delete(renderImageWidget);
      renderImageWidget = nullptr;
    }
    
    if (saveRenderImageButton != nullptr) {
      delete(saveRenderImageButton);
      saveRenderImageButton = nullptr;
    }

    if (previousRenderImageButton != nullptr) {
      delete(previousRenderImageButton);
      previousRenderImageButton = nullptr;
    }

    if (nextRenderImageButton != nullptr) {
      delete(nextRenderImageButton);
      nextRenderImageButton = nullptr;
    }

  } else if (errorLabel != nullptr) {
    delete(errorLabel);
    errorLabel = nullptr;
  }
}

QString RenderImageDialog::buildFullPath(const string fileName) {
  return QString("%1/%2").arg(dzApp->getTempPath(), QString::fromStdString(fileName));
}

QWidget* RenderImageDialog::buildRenderImageWidget(const QString filePath) {
  renderImage = new QImage(filePath);

  if (!renderImage->isNull()) {
    renderImageWidget = new QLabel();
    renderImageWidget->setPixmap(getScaledPixmap(renderImage));
    addSaveRenderImageButton();

    return renderImageWidget;
  }
  else {
    const QString message = QString("The rendering image %1 could not be loaded.").arg(filePath);
    errorLabel = new QLabel(message, this);
    saveRenderImageButton = nullptr;

    if (renderImage != nullptr) {
      delete(renderImage);
      renderImage = nullptr;
    }

    return errorLabel;
  }
}

void RenderImageDialog::updateRenderImageWidget(const int newCurrent) {
  RenderStatistics* nextStatistic = &statistics->at(newCurrent);
  renderImageWidget->clear();
  renderImageWidget->setPixmap(NULL);

  if (!renderImage->isNull() || renderImage != nullptr) {
    delete(renderImage);
    renderImage = nullptr;
  }

  renderImage = new QImage(buildFullPath(nextStatistic->getRenderImage()));
  renderImageWidget->setPixmap(getScaledPixmap(renderImage));
}

QPixmap RenderImageDialog::getScaledPixmap(QImage* renderImage) {
  if (renderImage->width() > DEFAULT_DIALOG_WIDTH) {
    return QPixmap::fromImage(renderImage->scaledToWidth(DEFAULT_DIALOG_WIDTH, Qt::FastTransformation));
  }
  else {
    dialogWidth = renderImage->width();
    return QPixmap::fromImage(*renderImage);
  }
}

void RenderImageDialog::addSaveRenderImageButton() {
  saveRenderImageButton = new QPushButton("Save", this);
  connect(saveRenderImageButton, SIGNAL(clicked()), this, SLOT(saveRenderImage()));
  addButton(saveRenderImageButton, SAVE_RENDER_IMAGE_BUTTON_POS);
}

void RenderImageDialog::addBrowseRenderImageButtons() {
  previousRenderImageButton = new QPushButton("Previous", this);
  connect(previousRenderImageButton, SIGNAL(clicked()), this, SLOT(showPreviousRenderImage()));
  addButton(previousRenderImageButton, PREVIOUS_RENDER_IMAGE_BUTTON_POS);

  nextRenderImageButton = new QPushButton("Next", this);
  connect(nextRenderImageButton, SIGNAL(clicked()), this, SLOT(showNextRenderImage()));
  addButton(nextRenderImageButton, NEXT_RENDER_IMAGE_BUTTON_POS);

  updateBrowsingButtons();
}

void RenderImageDialog::saveRenderImage() {
  const QString fileName = QFileDialog::getSaveFileName(
    this, "Save", dzApp->getDocumentsPath(), "Rendered Images (*.png *.jpg)"
  );

  if (fileName.isEmpty()) {
    return;
  }

  if (!renderImage->save(fileName, DEFAULT_IMAGE_FORMAT, DEFAULT_IMAGE_QUALITY)) {
    logger->log(QString("Failed saving rendering image to file %1.").arg(fileName));
  }

  if (QFile::exists(fileName)) {
    logger->log(QString("Saved rendering image to file %1.").arg(fileName));
  }
  
}

void RenderImageDialog::showPreviousRenderImage() {
  const int newCurrent = current - 1;
  if (newCurrent >= 0 && &statistics->at(newCurrent) != nullptr) {
    updateRenderImageWidget(--current);
    updateBrowsingButtons();
  }
}

void RenderImageDialog::showNextRenderImage() {
  const int newCurrent = current + 1;
  if (newCurrent < statistics->size() && &statistics->at(newCurrent) != nullptr) {
    updateRenderImageWidget(++current);
    updateBrowsingButtons();
  }
  
}

void RenderImageDialog::updateBrowsingButtons() {
  previousRenderImageButton->setDisabled(current - 1 < 0);
  nextRenderImageButton->setDisabled(current + 1 >= statistics->size());
}
