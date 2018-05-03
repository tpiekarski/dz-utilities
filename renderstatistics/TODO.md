dzUtilities::RenderStatistics
---

#### TODO

##### Features
+ [x] Temporarily save the rendered image
+ [x] Add a button to show a dialog with the rendered image
+ [ ] Add a setting dialog accessible by the pane actions menu
+ [x] Add a saving button in the RenderImageDialog to save the rendered image
+ [x] Inside the QStatisticsLayout indicate aborted and finished renderings
+ [ ] Introduce a setting to deactivate the capturing data from aborted renderings
+ [ ] Provide a setting for the width and the image scaling algorithm of the rendering image
+ [x] Clearing of all statistics and the QStatisticsLayout
+ [ ] Sorting of columns in the QStatisticsLayout
+ [ ] Saving of statistics inside DSON
+ [ ] Saving of rendered images inside DSON
+ [ ] Saving and of all important objects and settings during the rendering. 
      (Including camera, lights and all settings).
  + [ ] Storage of active camera
  + [ ] Storage of all active lights
  + [ ] Storage of render settings
+ [ ] Export of statistics to CSV and JSON

##### UI
+ [x] Avoid upscaling of smaller rendering images
+ [x] Add buttons to display previous and next rendering images
+ [ ] Handle different image sizes for browsing rendering images
+ [ ] Switch from DzBasicDialog to a more sophisticated window with scroll- and size-ability
+ [ ] Display gathered information inside the render image dialog
      (Probably also like a watermark-like imprint of stats)
+ [ ] Scroll-ability of the QStatisticsLayout
+ [ ] Replace show render button by either thumbnail or iconized button

##### Legal issues
+ [ ] Add legal disclaimer and Mozilla Public License

##### Development Improvements
+ [x] Streamline naming of headers and source files to lowercased underscore
+ [x] Extend logging with debug switch
+ [ ] Introduce automated click-tests with AutoIt
+ [ ] Introduce some kind of unit testing for the statistics framework
+ [x] Add another linter and static code analysis tool (cppcheck and ReSharper++ integrated)
+ [ ] Gather missing debug versions of certain libraries and switch 
      from production to debug build configuration
+ [ ] Integrate cloud-based build tools like AppVeyor or Travis
+ [x] Check possibility to reduce boost packages

##### Memory Improvements
+ [ ] Store rendering images for browsing instead of reloading at every display
+ [ ] Pass references of messages instead of copies to the logger
+ [x] Introduce reasonable memory deallocation
+ [x] Refactor handling of RenderStatisticsLogger
      _Instantiate logger only once in RenderStatisticsPane and pass
      a pointer into the classes where it is used and deallocate its
      memory only once inside the destructor of RenderStatisticsPane._

##### Clean code
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

#### Bugs
+ [x] Fix corrupt heap after closing RenderImageDialog
+ [x] Fix *Signal-Slot-Mapping bug* which maps signals multiple times
+ [x] Fix lost signal-slot-mapping for render image buttons after statistics clearing
      (Occurs only after clearing more than one statistic)
+ [x] Fix warning about missing argument for QString 
      (WARNING: QString::arg: Argument missing: RenderImageButton-, 2)
+ [x] Fix wrong saved render image after using previous/next buttons
+ [ ] Debug and solve heap corruption while destructing QStatisticsLayout
+ [ ] Debug missing version directive (WARNING: 0:1: '' :  #version directive missing)
+ [ ] Debugging and probably fixing or rewriting destructor of the RenderImageDialog
      _Under certain circumstances delete operations can cause memory access violations_
+ [ ] Fix different line breaks in a few files
