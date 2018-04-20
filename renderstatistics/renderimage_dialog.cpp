// Render Statistics Headers
#include "renderimage_dialog.h"

// Qt SDK Headers
#include "QtGui\qfiledialog.h"
#include "QtGui\qpushbutton.h"

RenderImageDialog::RenderImageDialog(
  QWidget* parent, const QString renderImageFilename, RenderStatisticsLogger* logger
) : DzBasicDialog(parent, "RenderImage") {

  this->logger = logger;

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

  showCancelButton(false);
  showHelpButton(false);

  QPushButton* saveButton = new QPushButton("Save", this);
  addButton(saveButton);
  connect(saveButton, SIGNAL(clicked()), this, SLOT(saveRenderImage()));
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

void RenderImageDialog::saveRenderImage() {
  const QString fileName = QFileDialog::getSaveFileName(this, "Save");
  
  if (!renderImage->save(fileName, 0, -1)) {
    logger->log(QString("Failed saving rendering image to file %1.").arg(fileName));
  }

  if (QFile::exists(fileName)) {
    logger->log(QString("Saved rendering image to file %1.").arg(fileName));
  }
  
}
