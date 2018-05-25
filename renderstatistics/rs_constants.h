/*
* Project:   dzUtilities::RenderStatistics
* Github:    https://github.com/tpiekarski/dzUtilities
* Copyright: (c) 2017-2018 Thomas Piekarski <t.piekarski@deloquencia.de>
* License:   Mozilla Public License, v. 2.0
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*/

#ifndef H_RENDERSTATISTICS_CONSTANTS
#define H_RENDERSTATISTICS_CONSTANTS

#define RS_ACTION_GROUP "Render Statistics"
#define RS_COLUMNS 7
#define RS_DATE_FACET_FORMAT "%m/%d/%Y"
#define RS_DEBUG true;
#define RS_DEFAULT_ABORTED_FORMAT "<i style='color:#b7b7b7'>%1</i>"
#define RS_DEFAULT_IMAGE_FORMAT 0
#define RS_DEFAULT_IMAGE_QUALITY -1
#define RS_DEFAULT_LABEL_SIZE 8
#define RS_DEFAULT_LOGGER_FORMAT "%1: %2"
#define RS_DEFAULT_RENDERIMAGE_BUTTON_BORDER 2
#define RS_DEFAULT_RENDERIMAGEBUTTON_ICON_FILENAME "renderimage.png"
#define RS_DEFAULT_RENDERIMAGEBUTTON_ICON_SUBDIRECTORY "renderstatistics"
#define RS_DURATION_DISPLAY_PRECISION 3
#define RS_HEADING_ROWS 2
#define RS_INITIAL_RENDERING_COUNTER 0
#define RS_NEXT_RENDER_IMAGE_BUTTON_POS 2
#define RS_NOTHING ""
#define RS_PANE_NOT_FOUND_MSG "Failed finding pane."
#define RS_PREVIOUS_RENDER_IMAGE_BUTTON_POS 1
#define RS_RENDER_FILE_NAME_TEMPLATE "render-%1.png"
#define RS_RENDER_IMAGE_DIALOG_DEFAULT_WIDTH 600
#define RS_RENDER_IMAGE_DIALOG_MAX_WIDTH 1200
#define RS_RENDER_IMAGE_DIALOG_MIN_WIDTH 400
#define RS_SAVE_RENDER_IMAGE_BUTTON_POS 3
#define RS_SETTINGS_DIALOG_WIDTH 300
#define RS_SETTINGS_PATH "RenderStatistics"
#define RS_SETTINGS_RENDERIMAGE_WIDTH_KEY "renderImageWidth"
#define RS_SETTINGS_RENDERIMAGE_WIDTH_READING_FAILED_MSG "Could not read saved render image width, falling back to default."
#define RS_TIME_FACET_FORMAT "%H:%M"

#endif