#pragma once
#include "statistics.h"
#include "QtCore\qstring.h"
#include "QtGui\qpushbutton.h"

class RenderImageButton : public QPushButton {

public:
  RenderImageButton(QString text);

signals:
  void clicked(RenderStatistics* statistic);
};

