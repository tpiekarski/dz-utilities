// Console Headers
#include "consolesettings.h"

// DAZ Studio SDK Headers
#include "dzapp.h"
#include "dzappsettings.h"

// Qt SDK Headers
#include "QtCore\qstring.h"


ConsoleSettings::ConsoleSettings() { 
  settings = new DzAppSettings(SETTINGS_PATH);
  loadFontSize();
}

ConsoleSettings::~ConsoleSettings() { 
  saveFontSize();
}

void ConsoleSettings::getFontSize(float *pFontSize) {
  bool ok;

  *pFontSize = this->fontSize.toFloat(&ok);

  if (!ok) *pFontSize = defaultFontSizeFloat;
}

void ConsoleSettings::getFontSize(QString *pFontSize) {
  *pFontSize = this->fontSize;
}

void ConsoleSettings::setFontSize(float fontSize) {
  this->fontSize = QString::number(fontSize, 'f', 2);
  saveFontSize();
}

void ConsoleSettings::setFontSize(QString fontSize) {
  this->fontSize = fontSize;
  saveFontSize();
}

void ConsoleSettings::loadFontSize() {
  bool readSuccess;

  fontSize = settings->getStringValue(
    SETTINGS_FONT_SIZE_KEY, 
    defaultFontSizeString, 
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