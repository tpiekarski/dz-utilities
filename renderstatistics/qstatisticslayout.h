#ifndef H_RENDERSTATISTICS_QSTATISTICS_LAYOUT
#define H_RENDERSTATISTICS_QSTATISTICS_LAYOUT

#include <vector>

// Render Statistics Headers
#include "statistics.h"
#include "logger.h"

// Qt SDK Headers
#include "QtCore\qalgorithms.h"
#include "QtCore\qlist.h"
#include "QtCore\qsignalmapper.h"
#include "QtGui\qgridlayout.h"
#include "QtGui\qlabel.h"
#include "QtGui\qpushbutton.h"


using namespace std;

class QStatisticsLayout : public QGridLayout {

	Q_OBJECT

public:
  QStatisticsLayout(vector<RenderStatistics>* statistics);
  ~QStatisticsLayout();
  void update();
  void clear();

signals:
  void clicked(const int &rendering);

private slots:
  void showRendering(const int &rendering);

private:  
  RenderStatisticsLogger* logger;
  QList<QLabel*> labels;
  QList<QPushButton*> buttons;
  QList<QSignalMapper*> signalMappers;
  vector<RenderStatistics>* statistics;

  void addSeparator(int row, int columnSpan);
  void removeRow(int row);
  QList<QLabel*> buildLabels();

};

#endif