/*
* Project:   dzUtilities::Console
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#include "console_constants.h"
#include "console_settings.h"
#include <dzapp.h>
#include <dzappsettings.h>
#include <QtCore/qregexp.h>
#include <QtCore/qstring.h>

ConsoleSettings::ConsoleSettings(const QString logFilePath) {
  this->logFilePath = logFilePath;
  settings = new DzAppSettings(SETTINGS_PATH);
  loadHighlightColor();
  loadFontSize();

  connect(dzApp, SIGNAL(closing()), this, SLOT(saveFontSize()));
  connect(dzApp, SIGNAL(closing()), this, SLOT(saveHighlightColor()));
}

void ConsoleSettings::getFontSize(float* fontSize) {
  bool castResult;
  *fontSize = this->fontSize.toFloat(&castResult);

  if (!castResult) {
    const float defaultFontSize = SETTINGS_DEFAULT_FONTSIZE;
    *fontSize = defaultFontSize;
  }
}

void ConsoleSettings::getFontSize(QString* fontSize) {
  *fontSize = this->fontSize;
}

void ConsoleSettings::setFontSize(const QString fontSize) {
  this->fontSize = fontSize;
}

bool ConsoleSettings::validateFontSize(const QString fontSize) {
  QRegExp regExp = QRegExp("(\\d+)");

  if (!regExp.exactMatch(fontSize)) {
    dzApp->log(SETTINGS_FONTSIZE_INVALID_MSG);

    return false;
  }

  bool castSuccess = false;
  const float size = fontSize.toFloat(&castSuccess);

  if (!castSuccess || size < SETTINGS_FONTSIZE_MIN || size > SETTINGS_FONTSIZE_MAX) {
    dzApp->log(SETTINGS_FONTSIZE_INVALID_MSG);

    return false;
  }

  return true;
}

void ConsoleSettings::setHighlightColor(const QColor hightlightColor) {
  this->highlightColor = hightlightColor;
}

void ConsoleSettings::saveFontSize() {
  settings->setStringValue(SETTINGS_FONTSIZE_KEY, fontSize);
}

void ConsoleSettings::saveHighlightColor() {
  settings->setColorValue(SETTINGS_HIGHLIGHT_COLOR_KEY, highlightColor);
}

void ConsoleSettings::loadFontSize() {
  bool readSuccess = false;
  QString storedFontSize = settings->getStringValue(
    SETTINGS_FONTSIZE_KEY, QString::number(SETTINGS_DEFAULT_FONTSIZE), &readSuccess
  );

  if (readSuccess && validateFontSize(storedFontSize)) {
    this->fontSize = storedFontSize;
  } else {
    dzApp->log(SETTINGS_FONTSIZE_READING_FAILED_MSG);
    this->fontSize = QString::number(SETTINGS_DEFAULT_FONTSIZE);;
    saveFontSize();
  }
}

void ConsoleSettings::loadHighlightColor() {
  bool readSuccess = false;
  QColor storedHighlightColor = settings->getColorValue(
    SETTINGS_HIGHLIGHT_COLOR_KEY, highlightColor, &readSuccess
  );

  if (readSuccess) {
    this->highlightColor = storedHighlightColor;
  }
  else {
    dzApp->log(SETTINGS_HIGHLIGHT_COLOR_READIND_FAILED_MSG);
    this->highlightColor = QColor(SETTINGS_DEFAULT_HIGHLIGHT_COLOR);
    saveHighlightColor();
  }
}
