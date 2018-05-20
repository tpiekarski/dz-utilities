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

#ifndef H_CONSOLE_SETTINGS
#define H_CONSOLE_SETTINGS

#include <dzappsettings.h>
#include <QtCore/qobject.h>
#include <QtCore/qstring.h>
#include <QtGui/qcolor.h>

class ConsoleSettings : public QObject {

  Q_OBJECT

public:
  ConsoleSettings(const QString logFilePath);
  ~ConsoleSettings() = default;

  void getFontSize(float* fontSize);
  void getFontSize(QString* fontSize);
  void setFontSize(const QString fontSize);
  bool validateFontSize(const QString fontSize);
  QColor getHighlightColor() { return highlightColor; };
  void setHighlightColor(const QColor hightlightColor);
  QString getLogFilePath() { return logFilePath; };

private slots:
  void saveFontSize();
  void saveHighlightColor();

private:
  DzAppSettings* settings;
  QString fontSize;
  QColor highlightColor;
  QString logFilePath;
  
  void loadFontSize();
  void loadHighlightColor();
  
};

#endif
