// Render Statistics Headers
#include "qstatisticslayout.h"
#include "renderimage-dialog.h"

// DAZ Studio SDK Headers
#include "dzmainwindow.h"

// Qt SDK Headers
#include "QtGui\qcolor.h"
#include "QtGui\qmessagebox.h"
#include "QtGui\qpalette.h"
#include "QtGui\qpushbutton.h"

QStatisticsLayout::QStatisticsLayout(vector<RenderStatistics>* statistics) : QGridLayout() {
  this->statistics = statistics;
  logger = new RenderStatisticsLogger();

  addHeadingRow();
  addSeparator(1, columnCount());

  logger->log("Connecting clicked signal with showRendering slot for future render image buttons.");
  connect(this, SIGNAL(clicked(const int &)), this, SLOT(showRendering(const int &)));
}

QStatisticsLayout::~QStatisticsLayout() {
  logger->log("Destructing QStatisticsLayout and clearing all lists with widgets.");

  delete(logger);
  logger = NULL;

  delete(statistics);
  statistics = NULL;

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
    label->setFixedHeight(15);
    addWidget(label, 0, row++);
  }
}

void QStatisticsLayout::update() {
  int currentColumn = 0;
  int currentRow = rowCount();

  dataRowLabelLists.append(buildLabels());

  for (QLabel* label : dataRowLabelLists.back()) {
    addWidget(label, currentRow, currentColumn++);
  }

  addRenderImageButton(currentRow);
}

void QStatisticsLayout::addRenderImageButton(const int currentRow) {
  int counter = statistics->back().getCounter() - 1;

  buttons.append(new QPushButton("Show"));
  addWidget(buttons.at(counter), currentRow, 6);

  QSignalMapper *newSignalMapper = new QSignalMapper(this);

  newSignalMapper->setMapping(buttons.at(counter), counter);
  newSignalMapper->setObjectName(QString("RenderImageButton-SignalMapper-%1").arg(QString::number(counter)));

  signalMappers.append(newSignalMapper);

  logger->log(QString("Adding mapped signal/slot connections to %1").arg(newSignalMapper->objectName()));
  connect(buttons.at(counter), SIGNAL(clicked()), signalMappers.at(counter), SLOT(map()));
  connect(signalMappers.at(counter), SIGNAL(mapped(const int &)), this, SIGNAL(clicked(const int &)));
}

void QStatisticsLayout::showRendering(const int &rendering) {
  RenderStatistics* currentStatistic = &statistics->at(rendering);
  DzMainWindow *mainWindow;
  RenderImageDialog* dialog;

  if (!(mainWindow = dzApp->getInterface())) {
    QMessageBox::warning(0, "Error", "The main window is not available.", QMessageBox::Ok);

    return;
  }

  if (!(dialog = new RenderImageDialog(mainWindow, QString::fromStdString(currentStatistic->getRenderImage())))) {
    QMessageBox::warning(0, "Error", "The dialog for render images could not be created.", QMessageBox::Ok);

    return;
  }

  dialog->exec();

  delete(dialog);
}

void QStatisticsLayout::removeRow(int row) {
  // todo: implement removing of rows
}

void QStatisticsLayout::addSeparator(int row, int columnSpan) {
  separator = new QFrame();
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

  for (QSignalMapper *signalMapper : signalMappers) {
    signalMapper->disconnect();
  }

  for (int n = 0; n < signalMappers.count(); n++) {
    QSignalMapper *signalMapper = signalMappers.at(n);

    if (signalMapper != NULL) {
      signalMapper->disconnect();
      delete signalMapper;
      signalMapper = NULL;

      signalMappers.removeAt(n);
    }
  }

  headingLabels.clear();
  dataRowLabelLists.clear();
  buttons.clear();

  addHeadingRow();
  addSeparator(1, columnCount());
}