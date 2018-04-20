// Render Statistics Headers
#include "renderimage_dialog.h"

// DAZ Studio SDK Headers
#include "dzapp.h"

// Qt SDK Headers
#include "QtGui\qfiledialog.h"
#include "QtGui\qlayout.h"

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

  addSaveRenderImageButton();
}

RenderImageDialog::~RenderImageDialog() {
  logger->log("Destructing render image dialog.");

  if (renderImage != nullptr) {
    delete(renderImage);
    renderImage = nullptr;
    delete(renderImageLabel);
    renderImageLabel = nullptr;
    delete(saveRenderImageButton);
    saveRenderImageButton = nullptr;
  } else if (errorLabel != nullptr) {
    delete(errorLabel);
    errorLabel = nullptr;
  } 
}

void RenderImageDialog::addSaveRenderImageButton() {
  saveRenderImageButton = new QPushButton("Save", this);
  connect(saveRenderImageButton, SIGNAL(clicked()), this, SLOT(saveRenderImage()));
  addButton(saveRenderImageButton);
}

void RenderImageDialog::saveRenderImage() {
  const QString fileName = QFileDialog::getSaveFileName(
    this, "Save", dzApp->getDocumentsPath(), "Rendered Images (*.png *.jpg)"
  );

  if (fileName.isEmpty()) {
    return;
  }

  if (!renderImage->save(fileName, 0, -1)) {
    logger->log(QString("Failed saving rendering image to file %1.").arg(fileName));
  }

  if (QFile::exists(fileName)) {
    logger->log(QString("Saved rendering image to file %1.").arg(fileName));
  }
  
}
