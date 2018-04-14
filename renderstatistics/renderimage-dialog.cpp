// Render Statistics Headers
#include "renderimage-dialog.h"

RenderImageDialog::RenderImageDialog(QWidget *parent, QString renderImageFilename)
  : DzBasicDialog(parent, "RenderImage") {

  logger = new RenderStatisticsLogger();

  QString renderStoragePath = dzApp->getTempPath();
  QString filePath = QString("%1/%2").arg(renderStoragePath, renderImageFilename);
  
  int dialogWidth = RENDER_IMAGE_DIALOG_WIDTH;
  renderImageLabel = new QLabel();
  renderImage = new QImage(filePath);

  if (! renderImage->isNull()) {

    if (renderImage->width() > RENDER_IMAGE_DIALOG_WIDTH) {
      QImage scaledRenderImage = renderImage->scaledToWidth(RENDER_IMAGE_DIALOG_WIDTH, Qt::FastTransformation);
      renderImageLabel->setPixmap(QPixmap::fromImage(scaledRenderImage));
    } else {
      renderImageLabel->setPixmap(QPixmap::fromImage(*renderImage));
      dialogWidth = renderImage->width();
    }

    addWidget(renderImageLabel);

  } else {
    QString message = QString("The rendering image %1 could not be loaded.").arg(filePath);
    errorLabel = new QLabel(message, this);

    addWidget(errorLabel);
  }

  int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
  layout()->setMargin(margin);
  layout()->setSpacing(margin);
  layout()->setSizeConstraint(QLayout::SetNoConstraint);

  setWindowTitle("Render Image");
  resize(QSize(dialogWidth, 0).expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());
}

RenderImageDialog::~RenderImageDialog() {
  logger->log("Destructing render image dialog.");

  delete(logger);
  logger = NULL;

  if (renderImage != NULL) {
    delete(renderImage);
    renderImage = NULL;
    delete(renderImageLabel);
    renderImageLabel = NULL;
  } else if (errorLabel != NULL) {
    delete(errorLabel);
    errorLabel = NULL;
  } 
}
