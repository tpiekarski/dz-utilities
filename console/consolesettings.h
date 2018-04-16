#ifndef H_CONSOLE_SETTINGS
#define H_CONSOLE_SETTINGS

// Console Headers
#include "constants.h"

// DAZ Studio SDK Headers
#include "dzappsettings.h"

// Qt SDK Headers
#include "QtCore\qobject.h"
#include "QtCore\qstring.h"

/*
 * Class: ConsoleSettings
 * Description: Container class for all settings.
 *
 */
class ConsoleSettings : public QObject {

  Q_OBJECT

public:
  QString fontSize;
  QString logFilePath;

  ConsoleSettings();
  virtual ~ConsoleSettings();

  void getFontSize(float* fontSize);
  void getFontSize(QString* fontSize);
  void setFontSize(const float fontSize);
  void setFontSize(const QString fontSize);
  QString getLogFilePath();
  void setLogFilePath(const QString logFilePath);

private slots:
  void saveFontSize();

private:
  DzAppSettings* settings;

  void loadFontSize();
  
};

#endif
