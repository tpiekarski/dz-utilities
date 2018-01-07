// Render Statistics Headers
#include "qstatisticslayout.h"

// Qt SDK Headers
#include "QtGui\qcolor.h"
#include "QtGui\qframe.h"
#include "QtGui\qpalette.h"

QStatisticsLayout::QStatisticsLayout() : QGridLayout() {
  labels.append(new QLabel("#"));
  labels.append(new QLabel("Engine"));
  labels.append(new QLabel("Nodes"));
  labels.append(new QLabel("Date"));
  labels.append(new QLabel("Time"));
  labels.append(new QLabel("Duration [s]"));

  int row = 0;

  for (QLabel* label : labels) {
    label->setFixedHeight(15);
    addWidget(label, 0, row++);
  }

  addSeparator(1, columnCount());
}

void QStatisticsLayout::update(vector<RenderStatistics>* statistics) {
  int currentColumn = 0;
  int currentRow = rowCount();

  for (QLabel* label : buildLabels(statistics)) {
    addWidget(label, currentRow, currentColumn++);
  }

}

void QStatisticsLayout::removeRow(int row) {
  
}

void QStatisticsLayout::addSeparator(int row, int columnSpan) {
  QFrame *separator = new QFrame();
  separator->setLineWidth(1);
  separator->setMidLineWidth(1);
  separator->setFrameShape(QFrame::HLine);
  separator->setPalette(QPalette(QColor(0, 0, 0)));

  addWidget(separator, row, 0, 1, columnSpan);
}

QList<QLabel*> QStatisticsLayout::buildLabels(vector<RenderStatistics>* statistics) {
  QList<QLabel*> outputLabels;

  RenderStatistics lastStatistics = statistics->back();

  outputLabels.append(new QLabel(QString::number(lastStatistics.getCounter())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics.getEngine())));
  outputLabels.append(new QLabel(QString::number(lastStatistics.getNodes())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics.getStartDate())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics.getStartTime())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics.getDurationInSeconds())));

  return outputLabels;
}