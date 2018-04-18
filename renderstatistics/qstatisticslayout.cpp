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

QStatisticsLayout::QStatisticsLayout(vector<RenderStatistics>* statistics, RenderStatisticsLogger* logger) 
  : QGridLayout() 
{
  this->setObjectName("QStatisticsLayout");
  this->statistics = statistics;

  this->logger = logger;

  addHeadingRow();
  addSeparator(1, columnCount());

  if (!connect(this, SIGNAL(clicked(const int &)), this, SLOT(showRendering(const int &)))) {
    logger->log(QString("Failed connecting clicked signal for %1 to the showRendering slot of %2 for future render image buttons.")
      .arg(this->objectName()).arg(this->objectName()));
  };
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

  QPushButton* newButton = new QPushButton("Show");
  newButton->setObjectName(QString("RenderImageButton-").arg(QString::number(counter)));
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
}

void QStatisticsLayout::showRendering(const int &rendering) {
  RenderStatistics* currentStatistic = &statistics->at(rendering);
  DzMainWindow* mainWindow;
  RenderImageDialog* dialog;

  if (!(mainWindow = dzApp->getInterface())) {
    QMessageBox::warning(0, "Error", "The main window is not available.", QMessageBox::Ok);

    return;
  }

  if (!(dialog = new RenderImageDialog(mainWindow, QString::fromStdString(currentStatistic->getRenderImage()), logger))) {
    QMessageBox::warning(0, "Error", "The dialog for render images could not be created.", QMessageBox::Ok);

    return;
  }

  dialog->exec();

  delete(dialog);
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

  addHeadingRow();
  addSeparator(1, columnCount());
}