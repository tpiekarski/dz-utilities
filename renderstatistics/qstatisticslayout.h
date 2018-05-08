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

#ifndef H_RENDERSTATISTICS_QSTATISTICS_LAYOUT
#define H_RENDERSTATISTICS_QSTATISTICS_LAYOUT

#include "dzstatistics.h"
#include "logger.h"
#include "qrenderimagebutton.h"
#include "statistics.h"
#include <QtCore/qlist.h>
#include <QtCore/qsignalmapper.h>
#include <QtGui/qframe.h>
#include <QtGui/qgridlayout.h>
#include <QtGui/qlabel.h>
#include <vector>

#define DEFAULT_RENDERIMAGEBUTTON_ICON_SUBDIRECTORY "renderstatistics"
#define DEFAULT_RENDERIMAGEBUTTON_ICON_FILENAME "renderimage.png"
#define DEFAULT_ABORTED_FORMAT "<i style='color:#b7b7b7'>%1</i>"
#define DEFAULT_LABEL_SIZE 8

using std::vector;

class QStatisticsLayout : public QGridLayout {

	Q_OBJECT

public:
  QStatisticsLayout(vector<DzRenderStatistics>* statistics, RenderStatisticsLogger* logger);
  ~QStatisticsLayout();
  void addDataRow();
  void addRenderImageButton(const int currentRow);
  void redraw();

signals:
  void clicked(const int &rendering);

private slots:
  void showRendering(const int &current);

private:
  RenderStatisticsLogger* logger;
  QList<QLabel*> headingLabels;
  QFrame* separator;
  QList<QList<QLabel*>> dataRowLabelLists;
  QList<QRenderImageButton*> buttons;
  QList<QSignalMapper*> signalMappers;
  vector<DzRenderStatistics>* statistics;

  void addHeadingRow();
  void addSeparator(const int row, const int columnSpan);
  QList<QLabel*> buildLabels();
  void clear();
  void setLabelSize(QLabel* label, const int size);
};
#endif