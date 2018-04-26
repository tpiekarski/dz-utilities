#include "clear_action.h"
#include "guid.h"
#include "pane.h"
#include "pane_action.h"
#include "version.h"
#include <dzapp.h>
#include <dzplugin.h>

/*
 * Plugin Meta Information
 */
DZ_PLUGIN_DEFINITION("Render Statistics")
DZ_PLUGIN_AUTHOR("Thomas Piekarski")
DZ_PLUGIN_VERSION(PLUGIN_MAJOR, PLUGIN_MINOR, PLUGIN_REV, PLUGIN_BUILD)
DZ_PLUGIN_DESCRIPTION(QString(
  "<strong>Render Statistics Plugin</strong>"
  "<p>"
  "This plugin provides basic render statistics to answer those questions like "
  "<em>how many renders did I started</em>, <em>how long did I wait in average "
  "for the final render</em> and <em>how often did I cancel a render</em> and "
  "a few more such questions."
  "</p>"
  "<p>"
  "For more information, current development and updates please see the "
  "<a href=\"#tba\">project website</a>."
  "</p>"
));

/*
 * Plugin Class GUID
 */
DZ_PLUGIN_CLASS_GUID(RenderStatisticsPane, RENDERSTATISTICS_PANE_CLASS_GUID)
DZ_PLUGIN_CLASS_GUID(RenderStatisticsPaneAction, RENDERSTATISTICS_PANE_ACTION_CLASS_GUID)
DZ_PLUGIN_CLASS_GUID(RenderStatisticsClearAction, RENDERSTATISTICS_CLEAR_ACTION_CLASS_GUID)
