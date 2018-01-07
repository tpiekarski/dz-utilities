#ifndef H_RENDERSTATISTICS_QSTATISTICS_LAYOUT
#define H_RENDERSTATISTICS_QSTATISTICS_LAYOUT

// Qt SDK Headers
#include "QtCore\qlist.h"
#include "QtGui\qgridlayout.h"
#include "QtGui\qlabel.h"

class QStatisticsLayout : public QGridLayout {

public:
  QStatisticsLayout();
  void removeRow(int row);

private:
  QList<QLabel*> labels;

  void addSeparator(int row, int columnSpan);
};

#endif