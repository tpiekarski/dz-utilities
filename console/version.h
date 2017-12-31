#ifndef H_CONSOLE_VERSION
#define H_CONSOLE_VERSION

// DAZ Studio SDK Headers
#include "dzversion.h"

/*
 * Version Definition
 */
#define PLUGIN_MAJOR 1
#define PLUGIN_MINOR 0
#define PLUGIN_REV 0
#define PLUGIN_BUILD 1

#define PLUGIN_VERSION DZ_MAKE_VERSION( \
  PLUGIN_MAJOR, PLUGIN_MINOR, PLUGIN_REV, PLUGIN_BUILD \
)

#endif
