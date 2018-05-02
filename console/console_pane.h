#ifndef H_CONSOLE_PANE
#define H_CONSOLE_PANE

#include "console.h"
#include "console_settings.h"
#include <dzactionmenu.h>
#include <dzpane.h>
#include <QtGui/qtextbrowser.h>
#include <QtGui/qtextcursor.h>

/*
 * Class: ConsolePane
 * Description: Main class for the console pane.
 */
class ConsolePane : public DzPane {

  Q_OBJECT

public:
  ConsolePane();
  ~ConsolePane();

  void clearLog();
  void showProperties();

public slots:
  void openLog();
  void updateLog();
  void reloadLog();

protected:
  void buildOptionsMenu(DzActionMenu* menu) const override;

private:
  Console* console;
  ConsoleSettings* settings;
  QTextBrowser* logBrowser;
  bool logWatched;

  void moveCursor(const QTextCursor::MoveOperation position);

};

#endif
