#ifndef H_CONSOLE_LOG_BROWSER
#define H_CONSOLE_LOG_BROWSER

#include "console.h"
#include "console_settings.h"
#include <QtCore/qobject.h>
#include <QtGui/qboxlayout.h>
#include <QtGui/qtextcursor.h>
#include <QtGui/qtextbrowser.h>

class ConsoleLogBrowser : public QObject {

  Q_OBJECT

public:
  ConsoleLogBrowser(QWidget* parent, Console* console, ConsoleSettings* settings);
  ~ConsoleLogBrowser();

  QHBoxLayout* getLayout() { return logBrowserLayout; };
  QTextBrowser* getBrowser() { return logBrowser; };
  void clearLog();

public slots:
  void openLog();
  void updateLog();
  void reloadLog();

private:
  Console* console;
  ConsoleSettings* settings;
  QHBoxLayout* logBrowserLayout;
  QTextBrowser* logBrowser;
  bool logWatched;

  void moveCursor(const QTextCursor::MoveOperation position);
};
#endif
