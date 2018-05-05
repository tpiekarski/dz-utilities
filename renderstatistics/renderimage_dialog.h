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

#ifndef H_RENDERSTATISTICS_RENDERIMAGE_DIALOG
#define H_RENDERSTATISTICS_RENDERIMAGE_DIALOG

#include "dzstatistics.h"
#include "logger.h"
#include <dzbasicdialog.h>
#include <dzstyle.h>
#include <QtCore/qstring.h>
#include <QtGui/qimage.h>
#include <QtGui/qlabel.h>
#include <QtGui/qpushbutton.h>

#define PREVIOUS_RENDER_IMAGE_BUTTON_POS 1
#define NEXT_RENDER_IMAGE_BUTTON_POS 2
#define SAVE_RENDER_IMAGE_BUTTON_POS 3
#define DEFAULT_DIALOG_WIDTH 600
#define DEFAULT_IMAGE_FORMAT 0
#define DEFAULT_IMAGE_QUALITY -1

/*
 * Class: RenderImageDialog
 * Description: Dialog for showing rendered image.
 */
class RenderImageDialog : public DzBasicDialog {

  Q_OBJECT

public:
  RenderImageDialog(
    QWidget* parent, 
    vector<DzRenderStatistics>* statistics, 
    const int current, 
    RenderStatisticsLogger* logger
  );
  
  virtual ~RenderImageDialog();

private slots:
  void saveRenderImage();
  void showPreviousRenderImage();
  void showNextRenderImage();

private:
  RenderStatisticsLogger* logger;
  QImage* renderImage;
  QLabel* renderImageWidget;
  QLabel* errorLabel;
  QPushButton* saveRenderImageButton;
  QPushButton* previousRenderImageButton;
  QPushButton* nextRenderImageButton;
  int dialogWidth;

  vector<DzRenderStatistics>* statistics;
  int current;

  QString buildFullPath(const string fileName);
  QWidget* buildRenderImageWidget(const QString filePath);
  void updateRenderImageWidget(const int newCurrent);
  QPixmap getScaledPixmap(QImage* renderImage);

  void addSaveRenderImageButton();
  void addBrowseRenderImageButtons();
  void updateBrowsingButtons();

};

#endif