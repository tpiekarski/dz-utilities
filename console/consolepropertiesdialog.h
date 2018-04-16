#ifndef H_CONSOLE_PROPERTIES_DIALOG
#define H_CONSOLE_PROPERTIES_DIALOG

// Console Headers
#include "consolesettings.h"
#include "constants.h"

// DAZ Studio SDK Headers
#include "dzbasicdialog.h"

// Qt SDK Headers
#include "QtCore\qstring.h"
#include "QtGui\qlabel.h"
#include "QtGui\qlineedit.h"

/*
 * Class: ConsolePropertiesDialog
 * Description: Dialog for setting up properties like font size.
 *
 */
class ConsolePropertiesDialog : public DzBasicDialog {

  Q_OBJECT

public:
  ConsolePropertiesDialog(QWidget* parent, ConsoleSettings* settings);
  virtual ~ConsolePropertiesDialog();

  QString getNewFontSize();

private:
  QLabel* fontSizeLabel;
  QLineEdit* fontSizeEditBox;
  QLabel* logFilePathLabel;
  QLineEdit* logFilePathDisplayBox;

};

#endif
