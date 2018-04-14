dzUtilities::RenderStatistics
---

#### TODO

##### Features
+ [x] Temporarily save rendered image
+ [x] Add a button to show a dialog with the rendered image
+ [ ] Saving button in the RenderImageDialog
+ [ ] Clearing of all statistics and the QStatisticsLayout
+ [ ] Sorting of columns inside the QStatisticsLayout
+ [ ] Saving of statistics inside DSON
+ [ ] Saving of rendered images inside DSON
+ [ ] Saving and recreating of all important objects and settings 
  during the rendering. Including camera, lights and all render settings.
+ [ ] Export of statistics to CSV and JSON

##### UI
+ [ ] Scrollability of the QStatisticsLayout
+ [ ] Replace show render button by either thumbnail or iconized button

##### Development Improvements
+ [ ] Streamline handling of header files
+ [ ] Introduce unit testing
+ [ ] Add a linter and static code analysis
+ [ ] Gather missing debug versions of certain libraries and switch 
      from production to debug build configuration

##### Memory Improvements
+ [x] Introduce reasonable memory deallocation
+ [ ] Refactor handling of RenderStatisticsLogger
  _Instantiate logger only once in RenderStatisticsPane and pass
   a pointer into the classes where it is used and deallocate its
   memory only once inside the destructor of RenderStatisticsPane._

#### Bugs
+ [ ] Fix *Signal-Slot-Mapping bug* which maps signals multiply times