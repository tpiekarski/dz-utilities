dzUtilities::RenderStatistics
---

#### TODO

##### Features
+ [x] Temporarily save rendered image
+ [x] Add a button to show a dialog with the rendered image
+ [ ] Add a setting dialog accessibly by the pane actions menu
+ [ ] Saving button in the RenderImageDialog
+ [ ] Indicate aborted renderings
+ [ ] Introduce a setting to capture data from aborted renderings
+ [x] Clearing of all statistics and the QStatisticsLayout
+ [ ] Sorting of columns inside the QStatisticsLayout
+ [ ] Saving of statistics inside DSON
+ [ ] Saving of rendered images inside DSON
+ [ ] Saving and recreating of all important objects and settings 
      during the rendering. Including camera, lights and all render settings.
+ [ ] Export of statistics to CSV and JSON

##### UI
+ [x] Avoid upscaling of smaller rendering images
+ [ ] Add buttons to display previous and next rendering images
+ [ ] Display gathered information inside the render image dialog
+ [ ] Provide a setting for the width and the image scaling algoritm of the rendering image
+ [ ] Scrollability of the QStatisticsLayout
+ [ ] Replace show render button by either thumbnail or iconized button

##### Legal issues
+ [ ] Add legal disclaimer and Mozilla Public License

##### Development Improvements
+ [ ] Extend logging with debug switch
+ [ ] Find best practise to streamline handling of header files
+ [ ] Introduce some kind of unit testing at least for the little statistics framework
+ [ ] Add another linter and static code analysis tool (cppcheck already integrated)
+ [ ] Gather missing debug versions of certain libraries and switch 
      from production to debug build configuration
+ [ ] Integrate cloud-based build tools like AppVeyor or Travis

##### Memory Improvements
+ [x] Introduce reasonable memory deallocation
+ [ ] Refactor handling of RenderStatisticsLogger
      _Instantiate logger only once in RenderStatisticsPane and pass
      a pointer into the classes where it is used and deallocate its
      memory only once inside the destructor of RenderStatisticsPane._

#### Bugs
+ [x] Fix *Signal-Slot-Mapping bug* which maps signals multiple times
+ [x] Fix lost signal-slot-mapping for render image buttons after statistics clearing
      (Occurs only after clearing more than one statistic)