dzUtilities::RenderStatistics
---

#### TODO

##### Features
+ [ ] Add a setting dialog accessible by the pane actions menu
+ [ ] Export images with watermarked statistics
+ [ ] Export of statistics to CSV and JSON
+ [ ] Introduce a setting to deactivate the capturing data from aborted renderings
+ [ ] Package and provide pre-compiled plugin library
+ [ ] Provide a setting for the width and the image scaling algorithm of the rendering image
+ [ ] Saving active camera
+ [ ] Saving all active lights
+ [ ] Saving render settings
+ [ ] Saving rendered images inside DSON
+ [ ] Saving statistics inside DSON
+ [ ] Sorting columns in the QStatisticsLayout
+ [x] Add a button to show a dialog with the rendered image
+ [x] Add a saving button in the RenderImageDialog to save the rendered image
+ [x] Clearing of all statistics and the QStatisticsLayout
+ [x] Inside the QStatisticsLayout indicate aborted and finished renderings
+ [x] Temporarily save the rendered image

##### UI
+ [ ] Display statistics inside the render image dialog
+ [ ] Handle different image sizes for browsing rendering images
+ [ ] Scroll-ability of the QStatisticsLayout
+ [ ] Switch from DzBasicDialog to a more sophisticated window with scroll- and size-ability
+ [x] Add buttons to display previous and next rendering images
+ [x] Avoid upscaling of smaller rendering images
+ [x] Replace show render button by iconized button


##### Legal issues
+ [x] Add legal disclaimer and Mozilla Public License

##### Development Improvements
+ [ ] Develop a CLI tool for deployment and replace batch scripts
+ [ ] Extract RenderStatisticsLogger to utility library, generalize and unit test
+ [ ] Gather missing debug versions and switch from release to debug build configuration
+ [ ] Integrate cloud-based build tools like AppVeyor or Travis
+ [ ] Introduce automated click-tests with AutoIt
+ [ ] Migrate and integrate new logger library
+ [x] Add linters and static code analysis tools (cppcheck and ReSharper++ integrated)
+ [x] Check possibility to reduce boost packages
+ [x] Collect all defined constants in one central constants header file
+ [x] Extend logging with debug switch
+ [x] Streamline naming of headers and source files to lowercased underscore


##### Memory Improvements
+ [ ] Pass references of messages instead of copies to the logger
+ [ ] Store rendering images for browsing instead of reloading at every display
+ [x] Introduce reasonable memory deallocation
+ [x] Refactor handling of RenderStatisticsLogger


##### Clean code
+ [ ] Check option for merging of destructor and clean() of QStatisticsLayout
+ [ ] Consider static resolving of method calls in constructors
      (Refers to inspection: Call to a virtual function inside a constructor will be statically resolved)
+ [ ] Check if const-qualified parameter should be defined in source as well as declared inside headers
      (Refers to inspection: Const-qualified parameter in a function declaration)
+ [ ] Check possible best practice to initialize fields with nullptr
+ [ ] Check binding of dereferenced null pointer and possible best practice
      (Refers to inspection: Reference cannot be bound to dereferenced null pointer in well-defined C++ code
       - comparison may be assumed to always evaluate to true)
+ [ ] Check comparing of signed and unsigned integers
      (Refers to inspection: Comparison of integers of different signs)

#### Unit tests
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
+ [ ] Fix VS Solution warning (Some of the properties associated with the solution could not be read).
+ [x] Fix warning about missing /MASCHINE argument during linking x86 library for testing
+ [x] Debug and fix _one-time_ callable methods for getting startDate and startTime
+ [x] Debugging and probably fixing or rewriting destructor of the RenderImageDialog
      (Under certain circumstances delete operations can cause memory access violations)
+ [x] Debug and fix destructor of the class QStatisticsLayout
      (It seems to be too early to delete statistics, memory access violations sometimes happens)
+ [x] Debug and solve heap corruption while destructing QStatisticsLayout
+ [x] Fix *Signal-Slot-Mapping bug* which maps signals multiple times
+ [x] Fix corrupt heap after closing RenderImageDialog
+ [x] Fix different line breaks in a few files
+ [x] Fix lost signal-slot-mapping for render image buttons after statistics clearing
+ [x] Fix warning about missing argument for QString 
+ [x] Fix wrong saved render image after using previous/next buttons
