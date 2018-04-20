dzUtilities::RenderStatistics
---

#### TODO

##### Features
+ [x] Temporarily save the rendered image
+ [x] Add a button to show a dialog with the rendered image
+ [ ] Add a setting dialog accessible by the pane actions menu
+ [x] Add a saving button in the RenderImageDialog to save the rendered image
+ [ ] Inside the QStatisticsLayout indicate aborted and finished renderings
+ [ ] Introduce a setting to deactivate the capturing data from aborted renderings
+ [ ] Provide a setting for the width and the image scaling algoritm of the rendering image
+ [x] Clearing of all statistics and the QStatisticsLayout
+ [ ] Sorting of columns in the QStatisticsLayout
+ [ ] Saving of statistics inside DSON
+ [ ] Saving of rendered images inside DSON
+ [ ] Saving and recreating of all important objects and settings 
      during the rendering. Including camera, lights and all render settings.
+ [ ] Export of statistics to CSV and JSON

##### UI
+ [x] Avoid upscaling of smaller rendering images
+ [ ] Add buttons to display previous and next rendering images
+ [ ] Display gathered information inside the render image dialog
+ [ ] Scrollability of the QStatisticsLayout
+ [ ] Replace show render button by either thumbnail or iconized button

##### Legal issues
+ [ ] Add legal disclaimer and Mozilla Public License

##### Development Improvements
+ [x] Streamline naming of headers and source files to lowercased underscore
+ [x] Extend logging with debug switch
+ [ ] Introduce some kind of unit testing at least for the little statistics framework
+ [ ] Add another linter and static code analysis tool (cppcheck already integrated)
+ [ ] Gather missing debug versions of certain libraries and switch 
      from production to debug build configuration
+ [ ] Integrate cloud-based build tools like AppVeyor or Travis
+ [ ] Check possibility to reduce boost packages

##### Memory Improvements
+ [x] Introduce reasonable memory deallocation
+ [x] Refactor handling of RenderStatisticsLogger
      _Instantiate logger only once in RenderStatisticsPane and pass
      a pointer into the classes where it is used and deallocate its
      memory only once inside the destructor of RenderStatisticsPane._

#### Bugs
+ [x] Fix corrupt heap after closing RenderImageDialog
+ [x] Fix *Signal-Slot-Mapping bug* which maps signals multiple times
+ [x] Fix lost signal-slot-mapping for render image buttons after statistics clearing
      (Occurs only after clearing more than one statistic)
