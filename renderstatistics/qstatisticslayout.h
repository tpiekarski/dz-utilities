#ifndef H_RENDERSTATISTICS_QSTATISTICS_LAYOUT
#define H_RENDERSTATISTICS_QSTATISTICS_LAYOUT

#include <vector>

// Render Statistics Headers
#include "statistics.h"

// Qt SDK Headers
#include "QtCore\qlist.h"
#include "QtGui\qgridlayout.h"
#include "QtGui\qlabel.h"

using namespace std;

class QStatisticsLayout : public QGridLayout {

public:
  QStatisticsLayout();
  void update(vector<RenderStatistics>* statistics);
  void clear();

private:
  QList<QLabel*> labels;
  vector<RenderStatistics> statistics;

  void addSeparator(int row, int columnSpan);
  void removeRow(int row);
  QList<QLabel*> buildLabels(vector<RenderStatistics>* statistics);
};

#endif