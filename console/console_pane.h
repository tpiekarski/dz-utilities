#ifndef H_CONSOLE_PANE
#define H_CONSOLE_PANE

#include "console.h"
#include "console_settings.h"
#include <dzactionmenu.h>
#include <dzpane.h>
#include <QtGui/qtextbrowser.h>

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
  void displayLog();
  void reloadLog();

protected:
  virtual void buildOptionsMenu(DzActionMenu* menu) const;

private:
  Console* console;
  ConsoleSettings* settings;
  QTextBrowser* logBrowser;

};

#endif
