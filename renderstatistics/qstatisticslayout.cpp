// Render Statistics Headers
#include "qstatisticslayout.h"
#include "renderimage-dialog.h"

// DAZ Studio SDK Headers
#include "dzmainwindow.h"

// Qt SDK Headers
#include "QtGui\qcolor.h"
#include "QtGui\qframe.h"
#include "QtGui\qpalette.h"
#include "QtGui\qpushbutton.h"
#include "QtGui\qmessagebox.h"

QStatisticsLayout::QStatisticsLayout(vector<RenderStatistics>* statistics) : QGridLayout() {
  this->statistics = statistics;

  labels.append(new QLabel("#"));
  labels.append(new QLabel("Engine"));
  labels.append(new QLabel("Nodes"));
  labels.append(new QLabel("Date"));
  labels.append(new QLabel("Time"));
  labels.append(new QLabel("Duration [s]"));
  labels.append(new QLabel("Rendering"));

  int row = 0;

  for (QLabel* label : labels) {
    label->setFixedHeight(15);
    addWidget(label, 0, row++);
  }

  addSeparator(1, columnCount());
}

void QStatisticsLayout::update() {
  int currentColumn = 0;
  int currentRow = rowCount();

  for (QLabel* label : buildLabels()) {
    addWidget(label, currentRow, currentColumn++);
  }

  int counter = statistics->back().getCounter() - 1;

  buttons.append(new QPushButton("Show"));
  addWidget(buttons.at(counter), currentRow, 6);
  
  signalMappers.append(new QSignalMapper(this));
  signalMappers.at(counter)->setMapping(buttons.at(counter), counter);

  connect(buttons.at(counter), SIGNAL(clicked()), signalMappers.at(counter), SLOT(map()));
  connect(signalMappers.at(counter), SIGNAL(mapped(const int &)), this, SIGNAL(clicked(const int &)));
  connect(this, SIGNAL(clicked(const int &)), this, SLOT(showRendering(const int &)));
}

void QStatisticsLayout::showRendering(const int &rendering) {
  RenderStatistics* currentStatistic = &statistics->at(rendering);
  DzMainWindow *mainWindow;
  RenderImageDialog* dialog;
  int dialogResult;

  if (!(mainWindow = dzApp->getInterface())) {
    QMessageBox::warning(0, "Error", "The main window is not available.", QMessageBox::Ok);

    return;
  }

  if (!(dialog = new RenderImageDialog(mainWindow, QString::fromStdString(currentStatistic->getRenderImage())))) {
    QMessageBox::warning(0, "Error", "The dialog for render images could not be created.", QMessageBox::Ok);

    return;
  }

  dialogResult = dialog->exec();

  delete(dialog);
}

void QStatisticsLayout::removeRow(int row) {
  // todo: implement removing of rows
}

void QStatisticsLayout::addSeparator(int row, int columnSpan) {
  QFrame *separator = new QFrame();
  separator->setLineWidth(1);
  separator->setMidLineWidth(1);
  separator->setFrameShape(QFrame::HLine);
  separator->setPalette(QPalette(QColor(0, 0, 0)));

  addWidget(separator, row, 0, 1, columnSpan);
}

QList<QLabel*> QStatisticsLayout::buildLabels() {
  QList<QLabel*> outputLabels;

  RenderStatistics* lastStatistics = &statistics->back();

  outputLabels.append(new QLabel(QString::number(lastStatistics->getCounter())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics->getEngine())));
  outputLabels.append(new QLabel(QString::number(lastStatistics->getNodes())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics->getStartDate())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics->getStartTime())));
  outputLabels.append(new QLabel(QString::fromStdString(lastStatistics->getDurationInSeconds())));
  
  return outputLabels;
}