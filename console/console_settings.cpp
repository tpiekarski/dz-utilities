#include "console_settings.h"
#include "constants.h"
#include <dzapp.h>
#include <dzappsettings.h>
#include <QtCore/qstring.h>

ConsoleSettings::ConsoleSettings() { 
  settings = new DzAppSettings(SETTINGS_PATH);
  loadFontSize();

  connect(dzApp, SIGNAL(closing()), this, SLOT(saveFontSize()));
}

void ConsoleSettings::getFontSize(float* fontSize) {
  bool ok;

  *fontSize = this->fontSize.toFloat(&ok);

  if (!ok) {
    const float defaultFontSize = DEFAULT_FONT_SIZE_FLOAT;
    *fontSize = defaultFontSize;
  }
}

void ConsoleSettings::getFontSize(QString* fontSize) {
  *fontSize = this->fontSize;
}

void ConsoleSettings::setFontSize(const float fontSize) {
  this->fontSize = QString::number(fontSize, 'f', 2);
}

void ConsoleSettings::setFontSize(const QString fontSize) {
  this->fontSize = fontSize;
}

void ConsoleSettings::loadFontSize() {
  bool readSuccess;

  fontSize = settings->getStringValue(
    SETTINGS_FONT_SIZE_KEY, 
    DEFAULT_FONT_SIZE_STRING,
    &readSuccess
  );

  if (!readSuccess) {
    dzApp->log(
      "Console: Could not read custom font size, "
      "falling back to default."
    );
  }
}

void ConsoleSettings::saveFontSize() {
  settings->setStringValue(SETTINGS_FONT_SIZE_KEY, fontSize);
}

QString ConsoleSettings::getLogFilePath() {
  return logFilePath;
}

void ConsoleSettings::setLogFilePath(const QString logFilePath) {
  this->logFilePath = logFilePath;
}