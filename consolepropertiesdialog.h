#ifndef H_CONSOLE_PROPERTIES_DIALOG
#define H_CONSOLE_PROPERTIES_DIALOG

// DAZ Studio SDK Headers
#include "dzbasicdialog.h"

// Qt SDK Headers


class ConsolePropertiesDialog : public DzBasicDialog {

  Q_OBJECT

public:
  ConsolePropertiesDialog(QWidget *parent);
  virtual ~ConsolePropertiesDialog();

};

#endif
