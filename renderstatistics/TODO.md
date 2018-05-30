dzUtilities::RenderStatistics
---

#### TODO

##### Features
+ [ ] *Export of statistics to CSV*
+ [ ] *Refactor and move to QTableView and utilize QAbstractTableModel*
+ [ ] Export images with watermarked statistics
+ [ ] Introduce a setting to deactivate the capturing data from aborted renderings
+ [ ] Make setting for the image scaling algorithm of the rendering image display persistent
+ [ ] Package and provide pre-compiled plugin library
+ [ ] Saving active camera (by duplicating camera and adding it to a node group for render history)
+ [ ] Saving all active lights (by duplicating lights and adding them to a new node group in the render history group)
+ [ ] Saving render settings
+ [ ] Saving statistics inside DSON
+ [x] Add a button to show a dialog with the rendered image
+ [x] Add a saving button in the RenderImageDialog to save the rendered image
+ [x] Add a settings dialog accessible by the pane actions menu
+ [x] Clearing of all statistics and the QStatisticsLayout
+ [x] Inside the QStatisticsLayout indicate aborted and finished renderings
+ [x] Make setting for the width of the rendering image display persistent
+ [x] Provide a setting for the image scaling algorithm of the rendering image display
+ [x] Provide a setting for the width of the rendering image display
+ [x] Temporarily save the rendered image

##### UI
+ [ ] Lay out widgets in RenderStatisticsSettingsDialog with QFormLayout
+ [ ] Display statistics inside the render image dialog
+ [ ] Scroll-ability of the QStatisticsLayout 
+ [ ] Switch from DzBasicDialog for the render image to a more sophisticated window with scroll- and size-ability ((Handle different image sizes for browsing rendering images))
+ [x] Add buttons to display previous and next rendering images
+ [x] Avoid upscaling of smaller rendering images
+ [x] Replace show render button by iconized button


##### Legal issues
+ [x] Add legal disclaimer and Mozilla Public License

##### Development Improvements
+ [ ] Check and try to avoid C-style casting when loading/saving Qt::TransformationMode
+ [ ] Develop a CLI tool for deployment and replace batch scripts
+ [ ] Extract RenderStatisticsLogger to utility library, generalize and unit test
+ [ ] Find better way to handle the default value for QSpinBox used for selecting scalingAlgorithm
+ [ ] Gather missing debug versions and switch from release to debug build configuration
+ [ ] Integrate cloud-based build tools like AppVeyor or Travis
+ [ ] Introduce automated click-tests with AutoIt
+ [ ] Introduce namespace *utils::renderstatistics* to avoid future collisions
+ [ ] Migrate and integrate new logger library
+ [ ] Use signal/slot-based updating of the settings instead of updating the values after the settings dialog closed
+ [x] Add linters and static code analysis tools (cppcheck and ReSharper++ integrated)
+ [x] Check possibility to reduce boost packages
+ [x] Collect all defined constants in one central constants header file
+ [x] Extend logging with debug switch
+ [x] Fix coliding constants header file in tests project
+ [x] Prefix all constants to avoid any future collisions with 3rd party constants
+ [x] Streamline file naming with prefix *rs_*  for avoiding filename collisions on the include path in the future
+ [x] Streamline naming of headers and source files to lowercased underscore


##### Memory Improvements
+ [ ] Pass references of messages instead of copies to the logger
+ [ ] Store rendering images for browsing instead of reloading at every display
+ [x] Deallocate memory for settings in RenderStatisticsSettings
+ [x] Introduce reasonable memory deallocation
+ [x] Refactor handling of RenderStatisticsLogger


##### Clean code
+ [ ] Check binding of dereferenced null pointer and possible best practice (Refers to inspection: Reference cannot be bound to dereferenced null pointer in well-defined C++ code- comparison may be assumed to always evaluate to true)
+ [ ] Check comparing of signed and unsigned integers (Refers to inspection: Comparison of integers of different signs)
+ [ ] Check if const-qualified parameter should be defined in source as well as declared inside headers (Refers to inspection: Const-qualified parameter in a function declaration)
+ [ ] Check option for merging of destructor and clean() of QStatisticsLayout
+ [ ] Check possible best practice to initialize fields with nullptr
+ [ ] Consider static resolving of method calls in constructors (Refers to inspection: Call to a virtual function inside a constructor will be statically resolved)

#### Unit tests
+ [ ] Add rounding of measured timing to avoid failing unit tests
+ [ ] Introduce unit testing for the DAZ layer
+ [ ] Introduce unit testing for the Qt layer
+ [x] Introduce unit testing for the statistics layer
  + [x] Test if statistics are collecting basic data
  + [x] Test if statistics are measuring time
  + [x] Test if statistics are providing duration in seconds
  + [x] Test if statistics are providing start date
  + [x] Test if statistics are providing start time
  + [x] Test if statistics are providing string representation

#### Bugs
+ [ ] Debug missing version directive (WARNING: 0:1: '' :  #version directive missing)
+ [x] Debug and fix _one-time_ callable methods for getting startDate and startTime
+ [x] Debug and fix destructor of the class QStatisticsLayout (It seems to be too early to delete statistics, memory access violations sometimes happens)
+ [x] Debug and solve heap corruption while destructing QStatisticsLayout
+ [x] Debugging and probably fixing or rewriting destructor of the RenderImageDialog (Under certain circumstances delete operations can cause memory access violations)
+ [x] Fix *Signal-Slot-Mapping bug* which maps signals multiple times
+ [x] Fix corrupt heap after closing RenderImageDialog
+ [x] Fix different line breaks in a few files
+ [x] Fix lost signal-slot-mapping for render image buttons after statistics clearing
+ [x] Fix VS Solution warning (Some of the properties associated with the solution could not be read).
+ [x] Fix warning about missing /MASCHINE argument during linking x86 library for testing
+ [x] Fix warning about missing argument for QString 
+ [x] Fix wrong saved render image after using previous/next buttons
