// Render Statistics Headers
#include "renderimage_dialog.h"

// DAZ Studio SDK Headers
#include "dzapp.h"

// Qt SDK Headers
#include "QtGui\qfiledialog.h"
#include "QtGui\qlayout.h"

RenderImageDialog::RenderImageDialog(
  QWidget* parent, vector<RenderStatistics>* statistics, const int current, RenderStatisticsLogger* logger
) : DzBasicDialog(parent, "RenderImage") {

  RenderStatistics* currentStatistic = &statistics->at(current);

  this->logger = logger;

  const QString filePath = QString("%1/%2").arg(
    dzApp->getTempPath(), QString::fromStdString(currentStatistic->getRenderImage())
  );
  
  int dialogWidth = RENDER_IMAGE_DIALOG_WIDTH;
  const int margin = style()->pixelMetric(DZ_PM_GeneralMargin);

  addWidget(buildRenderImageWidget(filePath, &dialogWidth));

  layout()->setMargin(margin);
  layout()->setSpacing(margin);
  layout()->setSizeConstraint(QLayout::SetNoConstraint);

  setWindowTitle("Render Image");
  resize(QSize(dialogWidth, 0).expandedTo(minimumSizeHint()));
  setFixedWidth(width());
  setFixedHeight(height());

  showCancelButton(false);
  showHelpButton(false);
}

RenderImageDialog::~RenderImageDialog() {
  logger->log("Destructing render image dialog.");

  if (renderImage != nullptr) {
    delete(renderImage);
    renderImage = nullptr;
    delete(renderImageWidget);
    renderImageWidget = nullptr;
    
    if (saveRenderImageButton != nullptr) {
      delete(saveRenderImageButton);
      saveRenderImageButton = nullptr;
    }
  } else if (errorLabel != nullptr) {
    delete(errorLabel);
    errorLabel = nullptr;
  } 
}

QWidget* RenderImageDialog::buildRenderImageWidget(const QString filePath, int* width) {
  renderImage = new QImage(filePath);

  if (!renderImage->isNull()) {
    renderImageWidget = new QLabel();

    if (renderImage->width() > RENDER_IMAGE_DIALOG_WIDTH) {
      QImage scaledRenderImage = renderImage->scaledToWidth(RENDER_IMAGE_DIALOG_WIDTH, Qt::FastTransformation);
      renderImageWidget->setPixmap(QPixmap::fromImage(scaledRenderImage));
    }
    else {
      renderImageWidget->setPixmap(QPixmap::fromImage(*renderImage));

      int newWidth = renderImage->width();
      width = &newWidth;
    }

    addSaveRenderImageButton();
    return renderImageWidget;
  }
  else {
    QString message = QString("The rendering image %1 could not be loaded.").arg(filePath);
    errorLabel = new QLabel(message, this);
    if (renderImage != nullptr) {
      logger->log("Something is there, renderimage is not null!");
      delete(renderImage);
      renderImage = nullptr;
    }
    saveRenderImageButton = nullptr;

    return errorLabel;
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
