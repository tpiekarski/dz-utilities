#ifndef H_CONSOLE_SETTINGS
#define H_CONSOLE_SETTINGS

// DAZ Studio SDK Headers
#include "dzappsettings.h"

// Qt SDK Headers
#include "QtCore\qobject.h"
#include "QtCore\qstring.h"

#define SETTINGS_PATH "Console"
#define SETTINGS_FONT_SIZE_KEY "fontSize"

// Fallback values
static float defaultFontSizeFloat = 10.0;
static const QString defaultFontSizeString = "10.00";

/*
 * Class: ConsoleSettings
 * Description: Container class for all settings.
 *
 */
class ConsoleSettings : public QObject {

  Q_OBJECT

public:
  QString fontSize;

  ConsoleSettings();
  virtual ~ConsoleSettings();

  // Getter by reference
  void getFontSize(float *fontSize);
  void getFontSize(QString *fontSize);
  
  void setFontSize(float fontSize);
  void setFontSize(QString fontSize);

private slots:
  void saveFontSize();

private:
  DzAppSettings *settings;

  void loadFontSize();
  
};

#endif
