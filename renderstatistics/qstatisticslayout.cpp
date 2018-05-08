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

#include "qstatisticslayout.h"
#include "renderimage_dialog.h"
#include <dzmainwindow.h>
#include <QtGui/qcolor.h>
#include <QtGui/qmessagebox.h>
#include <QtGui/qpalette.h>

QStatisticsLayout::QStatisticsLayout(vector<DzRenderStatistics>* statistics, RenderStatisticsLogger* logger) {
  this->setObjectName("QStatisticsLayout");
  this->statistics = statistics;

  this->logger = logger;

  addHeadingRow();
  addSeparator(1, columnCount());

  if (!connect(this, SIGNAL(clicked(const int &)), this, SLOT(showRendering(const int &)))) {
    logger->log(QString("Failed connecting clicked signal for %1 to the showRendering slot of %2.")
      .arg(this->objectName()).arg(this->objectName()));
  };
}

QStatisticsLayout::~QStatisticsLayout() {
  logger->log("Destructing QStatisticsLayout and clearing all lists with widgets.");

  if (signalMappers.count() > 0) {
    qDeleteAll(signalMappers);
    signalMappers.clear();
  }
  
  if (buttons.count() > 0) {
    qDeleteAll(buttons);
    buttons.clear();
  }
  
  if (headingLabels.count() > 0) {
    qDeleteAll(headingLabels);
    headingLabels.clear();
  }
  
  if (dataRowLabelLists.count() > 0) {
    for (QList<QLabel*> dataRowList : dataRowLabelLists) {
      if (dataRowList.count() > 0) {
        qDeleteAll(dataRowList);
        dataRowList.clear();
      }
    }
  }

}

void QStatisticsLayout::redraw() {
  clear();
  addHeadingRow();
  addSeparator(1, columnCount());
}

void QStatisticsLayout::addHeadingRow() {
  headingLabels.append(new QLabel("#"));
  headingLabels.append(new QLabel("Engine"));
  headingLabels.append(new QLabel("Nodes"));
  headingLabels.append(new QLabel("Date"));
  headingLabels.append(new QLabel("Time"));
  headingLabels.append(new QLabel("Duration [s]"));
  headingLabels.append(new QLabel("Rendering"));

  int row = 0;

  for (QLabel* label : headingLabels) {
    setLabelSize(label, DEFAULT_LABEL_SIZE);

    addWidget(label, 0, row++);
  }
}

void QStatisticsLayout::addDataRow() {
  int currentColumn = 0;
  const int currentRow = rowCount();

  dataRowLabelLists.append(buildLabels());

  for (QLabel* label : dataRowLabelLists.back()) {
    setLabelSize(label, DEFAULT_LABEL_SIZE);
    addWidget(label, currentRow, currentColumn++);
  }

  addRenderImageButton(currentRow);
}

void QStatisticsLayout::addRenderImageButton(const int currentRow) {
  const int counter = statistics->back().getCounter() - 1;

  const QString iconFullPath = QString("%1/%2/%3").arg(
    dzApp->getPluginsPath(),
    DEFAULT_RENDERIMAGEBUTTON_ICON_SUBDIRECTORY,
    DEFAULT_RENDERIMAGEBUTTON_ICON_FILENAME
  );

  QRenderImageButton* newButton = new QRenderImageButton(iconFullPath, logger);
  newButton->setObjectName(QString("RenderImageButton-%1").arg(QString::number(counter)));
  buttons.append(newButton);
  QSignalMapper* newSignalMapper = new QSignalMapper(this);
  newSignalMapper->setMapping(buttons.at(counter), counter);
  newSignalMapper->setObjectName(QString("RenderImageButton-SignalMapper-%1").arg(QString::number(counter)));
  signalMappers.append(newSignalMapper);

  if (!connect(buttons.at(counter), SIGNAL(clicked()), signalMappers.at(counter), SLOT(map()))) {
    logger->log(QString("Failed connecting clicked signal for %1 to the map slot of %2.")
      .arg(newButton->objectName()).arg(newSignalMapper->objectName()));
    
    return;
  }

  if (!connect(signalMappers.at(counter), SIGNAL(mapped(const int &)), this, SIGNAL(clicked(const int &)))) {
    logger->log(QString("Failed connecting mapped signal for %1 to the clicked signal for %2")
      .arg(newSignalMapper->objectName()).arg(this->objectName()));

    return;
  }

  addWidget(newButton, currentRow, 6);
  setAlignment(newButton, Qt::AlignHCenter);
}

void QStatisticsLayout::showRendering(const int &current) {
  DzMainWindow* mainWindow = dzApp->getInterface();
  if (mainWindow == nullptr) {
    QMessageBox::warning(0, "Error", "The main window is not available.", QMessageBox::Ok);

    return;
  }

  RenderImageDialog* dialog = new RenderImageDialog(mainWindow, statistics, current, logger);
  if (dialog == nullptr) {
    QMessageBox::warning(0, "Error", "The dialog for render images could not be created.", QMessageBox::Ok);

    return;
  }

  dialog->exec();
  delete(dialog);
  dialog = nullptr;
}

void QStatisticsLayout::addSeparator(const int row, const int columnSpan) {
  separator = new QFrame();
  separator->setLineWidth(1);
  separator->setMidLineWidth(1);
  separator->setFrameShape(QFrame::HLine);
  separator->setPalette(QPalette(QColor(0, 0, 0)));

  addWidget(separator, row, 0, 1, columnSpan);
}

QList<QLabel*> QStatisticsLayout::buildLabels() {
  QList<QLabel*> outputLabels;

  RenderStatistics* lastStatistic = &statistics->back();

  outputLabels.append(new QLabel(QString::number(lastStatistic->getCounter())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistic->getEngine())));
  outputLabels.append(new QLabel(QString::number(lastStatistic->getNodes())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistic->getStartDate())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistic->getStartTime())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistic->getDurationInSeconds())));

  if (!lastStatistic->isSucceeded()) {
    for (int n = 0; n < outputLabels.count(); n++) {
      QLabel* label = outputLabels.at(n);
      if (label != nullptr) {
        label->setTextFormat(Qt::RichText);
        label->setText(QString(DEFAULT_ABORTED_FORMAT).arg(label->text()));
      }
    }

  }

  return outputLabels;
}

void QStatisticsLayout::setLabelSize(QLabel* label, const int size) {
  QFont currentFont = label->font();
  currentFont.setPointSize(size);
  label->setFont(currentFont);
  label->setFixedHeight(size * 2);
}

void QStatisticsLayout::clear() {
  while (count()) {
    QWidget* widget = itemAt(0)->widget();

    if (widget != NULL) {
      widget->setVisible(false);
      removeWidget(widget);
      delete widget;
      widget = NULL;
    }
  }

  for (QSignalMapper* signalMapper : signalMappers) {
    signalMapper->disconnect();
  }

  for (int n = 0; n < signalMappers.count(); n++) {
    QSignalMapper* signalMapper = signalMappers.at(n);

    if (signalMapper != NULL) {
      signalMapper->disconnect();
      delete signalMapper;
      signalMapper = NULL;

      signalMappers.removeAt(n);
    }
  }

  buttons.clear();
  dataRowLabelLists.clear();
  headingLabels.clear();
  signalMappers.clear();
}