#ifndef H_RENDERSTATISTICS_QSTATISTICS_LAYOUT
#define H_RENDERSTATISTICS_QSTATISTICS_LAYOUT

#include "dzstatistics.h"
#include "logger.h"
#include "statistics.h"
#include <QtCore/qlist.h>
#include <QtCore/qsignalmapper.h>
#include <QtGui/qframe.h>
#include <QtGui/qgridlayout.h>
#include <QtGui/qlabel.h>
#include <QtGui/qpushbutton.h>
#include <vector>

using namespace std;

class QStatisticsLayout : public QGridLayout {

	Q_OBJECT

public:
  QStatisticsLayout(vector<DzRenderStatistics>* statistics, RenderStatisticsLogger* logger);
  ~QStatisticsLayout();
  void update();
  void addRenderImageButton(const int currentRow);
  void clear();

signals:
  void clicked(const int &rendering);

private slots:
  void showRendering(const int &current);

private:
  RenderStatisticsLogger* logger;
  QList<QLabel*> headingLabels;
  QFrame* separator;
  QList<QList<QLabel*>> dataRowLabelLists;
  QList<QPushButton*> buttons;
  QList<QSignalMapper*> signalMappers;
  vector<DzRenderStatistics>* statistics;

  void addHeadingRow();
  void addSeparator(const int row, const int columnSpan);
  QList<QLabel*> buildLabels();
};
#endif