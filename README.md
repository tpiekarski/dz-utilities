dzUtilities
---

*A collection of miscellaneous utilities for [DAZ Studio](https://www.daz3d.com/get_studio).*

#|Utility Plugin|Description|TODO|Source
---|---|---|---|---
1.|[Console](#console)|Console plugin displaying DAZ Studio Log file|[TODO](https://github.com/tpiekarski/dzUtilities/blob/master/console/TODO.md)|[dzUtilities/console](https://github.com/tpiekarski/dzUtilities/tree/master/console)
2.|[Render Statistics](#render-statistics)|Render data aggregation and statistics plugin|[TODO](https://github.com/tpiekarski/dzUtilities/blob/master/renderstatistics/TODO.md)|[dzUtilities/renderstatistics](https://github.com/tpiekarski/dzUtilities/tree/master/renderstatistics)

#### Build process
Visual Studio is used for the build process and all project configurations are
provided inside this repository. There is one solution provided which keeps all
single projects and can be compiled into individual dynamically linked libraries.

In the scripts directory is a deployment batch file, which is triggered by
post-built event to copy the final DLL into DAZ Studios plugin directory.
The batch file can only copy the DLL when DAZ Studio is not running in the background,
especially when the DLL is to be replaced. Do not run this batch file directly,
it is supposed to be started by the build process of Visual Studio.

##### Environment Variables
Following environment variables are necessary for the build process. When you are using
your own variables so please update additional include directories for the preprocessor,
library directories for the linker and post-built event setup for the deployment in the
project configurations accordingly.

Variable|Description
---|---
DAZ_SDK|The full path to DAZ Studio SDK (Used for generating metaobjects with moc)
DAZ_STUDIO|The full path to DAZ Studio (Used for post-built deployment)

#### Requirements
- [Visual Studio 2017](https://www.visualstudio.com/)
  (Developed and tested with platform toolsets v141 and v140, both at x64)
- [DAZ Studio SDK](https://www.daz3d.com/daz-studio-4-5-sdk) > 4.5.x
- [DAZ Studio](https://www.daz3d.com/get_studio) > 4.5.x
- [Qt](https://www.qt.io/) 4.x (not needed, the DAZ Studio SDK contains Qt)

#### NuGet Packages
- [boost](https://www.nuget.org/packages/boost/) 1.65.1 (VC 140)
- [boost_date_time 1.65.1](https://www.nuget.org/packages/boost_date_time-vc140/) (VC 140)

### Console
#### Introduction
Console is a plugin for DAZ Studio for displaying the internal log file
in a convenient window pane, which is size- and dock-able. By a few events
provided by Qt signal and slot concept the display is automatically updated,
like after finishing a rendering. Next to these signals it is possible to update
it manually, clear the displayed lines and set the font size in a property
dialog.

![Screenshot of Console](images/console.jpg?raw=true "Screenshot of Console")

#### Background
The purpose of this plugin is development and testing while discovering the DAZ
Studio SDK and Qt during studies, creating little utility plugins and in search
for possibilities to develop a rendering interface for the CLI - making (scheduled)
batch rendering possible.

This journey for developing a rendering interface for the CLI stopped when I
encountered following message: *Rendering cannot be performed without the interface.*

Nevertheless, this disillusioning result I wanted to provide this utility and
encourage users to dive into developing plugins. It is challenging to work only
with an SDK without being able to ask Google for help and turning often to the
Header files itself and it is rewarding after hours of try-and-error to finally
getting an idea to work or not.

### Render Statistics
#### Introduction
Renderstatistics is a work-in-progress plugin for collecting different rendering data.
Following data is aggregated during rendering time and displayed in a pane.

#|Data|Description
---|---|---
1.|Rendering Engine|Engines like 3Delight or Nvidia Iray
2.|Amount of Nodes|Amount of all nodes in scene (at the moment it contains also invisible nodes)
3.|Date & Time|Just the date and time when the rendering was started
4.|Duration|The rendering time in seconds

![Screenshot of Render Statistics](images/renderstatistics.jpg?raw=true "Screenshot of Render Statistics")

#### Outlook
There is way more data to acquire, collect and aggregate. The collected data is not
yet persistent and saved. It is only stored in the memory allocated to the current
running DAZ Studio process. In near future it is planned to persist the data either
in a global or in a scene-based storage inside the
[DSON](http://docs.daz3d.com/doku.php/public/dson_spec/start) Scene files.

Furthermore, the idea is to go one step ahead of plain statistics in integrating a thumbnail
image of the finished rendering and to store render settings and the rendering camera which
have been used for quick and convenient access.
