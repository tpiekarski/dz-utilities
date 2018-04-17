// DAZ Studio SDK Headers
#include "dzplugin.h"

// Console Headers
#include "consolepane.h"
#include "consolepaneaction.h"
#include "console_clear_action.h"
#include "console_reload_action.h"
#include "console_properties_action.h"
#include "guid.h"
#include "version.h"

/*
 * Plugin Meta Information
 */
DZ_PLUGIN_DEFINITION("Console");
DZ_PLUGIN_AUTHOR("Thomas Piekarski");
DZ_PLUGIN_VERSION(PLUGIN_MAJOR, PLUGIN_MINOR, PLUGIN_REV, PLUGIN_BUILD);
DZ_PLUGIN_DESCRIPTION(
  "<strong>Console Plugin</strong>"
  "<p>"
  "This plugin provides a console to the log file of DAZ Studio. The console is "
  "integrated as a pane and the purpose is for development, debugging and testing "
  "of new utility Plug-Ins."
  "</p>"
  "<p>"
  "For more information, current development and updates please see the "
  "<a href=\"#tba\">project website</a>."
  "</p>"
);

/*
 * Plugin Class GUID
 */
DZ_PLUGIN_CLASS_GUID(ConsolePane, CONSOLE_PANE_CLASS_GUID);
DZ_PLUGIN_CLASS_GUID(ConsolePaneAction, CONSOLE_PANE_ACTION_CLASS_GUID);
DZ_PLUGIN_CLASS_GUID(ConsoleClearAction, CONSOLE_CLEAR_ACTION_CLASS_GUID);
DZ_PLUGIN_CLASS_GUID(ConsoleReloadAction, CONSOLE_RELOAD_ACTION_CLASS_GUID);
DZ_PLUGIN_CLASS_GUID(ConsolePropertiesAction, CONSOLE_PROPERTIES_ACTION_CLASS_GUID);
