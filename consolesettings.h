#ifndef H_CONSOLE_SETTINGS
#define H_CONSOLE_SETTINGS

// DAZ Studio SDK Headers
#include "dzappsettings.h"

// Qt SDK Headers
#include "QtCore\qstring.h"

#define FONT_SIZE_KEY "fontSize"

class ConsoleSettings {

public:
  ConsoleSettings();
  ~ConsoleSettings();

  void getFontSize(float* fontSize);
  void getFontSize(QString* fontSize);
  
  void setFontSize(float fontSize);
  void setFontSize(QString fontSize);

private:
  DzAppSettings* settings;
  QString fontSize;

  void loadFontSize();
  void saveFontSize();

};

#endif
