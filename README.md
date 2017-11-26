dzConsole
---

#### Introduction
dzConsole is a plugin for DAZ Studio for displaying the internal log file
in a convenient window pane, which is size- and dockable. By a few events
provided by Qt signal and slot concept the display is automatically updated,
like after finishing a rendering. Next to these signals it is possible to update
it manually, clear the displayed lines and set the font size in a property
dialog.

![Screenshot of dzConsole](img/screenshot.jpg?raw=true "Screenshot of dzConsole")


#### Background
The purpose of this plugin is development and testing while discovering the DAZ
Studio SDK and Qt during studies, creating little utility plugins and in search
for possibilities to develop a rendering interface for the CLI - making (scheduled)
batch rendering possible.

This journey for developing a rendering interface for the CLI stopped when I
encountered following message: *Rendering cannot be performed without the interace.*

Nevertheless, this disillusioning result I wanted to provide this utility an´d
encourage users to dive into developing plugins. It is challenging to work only
with an SDK without being able to ask Google for help and turning often to the
Header files itself and it is rewarding after hours of try-and-error to finally
getting an idea to work or not.

#### Requirements
- Visual Studio 2017 (Developed and tested with v141)
- DAZ Studio SDK > 4.5.x
- DAZ Studio > 4.5.x
- Qt 4.x (is not needed, the DAZ Studio SDK contains Qt)

#### Build process
For the build process Visual Studio is used and the project configuration is
provided inside this repository. This configuration can be attached to solution
and can be compiled into a dynamically linked library. 

In the scripts directory is a little deployment batch file, which is triggered by
post-built event to copy the final DLL into DAZ Studios plugin directory. 
For this copy after the build process DAZ Studio cannot run in the background,
especially when the DLL is to be replaced. Do not run this batch file directly,
it is supposed to be started by VC build process.

##### Environment Variables

Following environment variables are necessary for the build process

Variable|Description
---|---
DAZ_SDK|The full path to DAZ Studio SDK (Used for generating metaobjects with moc)
DAZ_STUDIO|The full path to DAZ Studio (Used for post-built deployment)
