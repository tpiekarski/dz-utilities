dzUtilities::Console
---

#### TODO

##### Features
+ [ ] Add filter for the issuer of log messages
+ [ ] Add the possibility to search for keywords forward and backward
+ [ ] Highlight search results
+ [ ] Improve speed of seeking to 0 when reloading log
+ [ ] Package and provide pre-compiled plugin library
+ [x] Include input validation for the font size and provide fallback mechanism
+ [ ] Change or extend input widget for the font size with increase/decrease buttons
+ [x] Automatically redisplay the log when new messages have been written the log file
+ [x] Remove most of previous signal-slot-based update connections

##### UI
+ [x] Move control buttons into pane action menu

##### Legal issues
+ [x] Add legal disclaimer and Mozilla Public License

##### Development Improvements
+ [ ] Migrate and integrate new logger library
+ [ ] Develop a CLI tool for deployment and replace batch scripts
+ [ ] Integrate cloud-based build tools like AppVeyor or Travis
+ [ ] Refactor ConsoleSettings and ConsolePropertiesDialog
      (Restructure access to properties, remove unused methods and various other little improvements)
+ [x] Add another linter and static code analysis tool (cppcheck and ReSharper++ integrated)
+ [x] Implement error handling inside menu actions when ConsolePane cannot be found
+ [x] Streamline naming of headers and source files to lowercased underscore

##### Memory Improvements
+ [x] Keep log file opened instead of opening/closing at every call to displayLog
      (see bugs:debug and solve delaying and blocking behavior)

##### Clean code
+ [ ] Check if const-qualified parameter should be defined in source as well as declared inside headers
      (Refers to inspection: Const-qualified parameter in a function declaration)
+ [ ] Consider static resolving of method calls in constructors
      (Refers to inspection: Call to a virtual function inside a constructor will be statically resolved)

#### Unit tests
+ [ ] Introduce unit testing for the DAZ layer
+ [ ] Introduce unit testing for the Qt layer
+ [x] Introduce unit testing for the console layer
  + [x] Test if console is opening log file
  + [x] Test if console is providing log content
  + [x] Test if console is providing log updates
  + [x] Test if console is resetting log file
  + [x] Test if console is closing log file

#### Bugs
+ [ ] Fix initial log display bug sometimes not showing the end of file (off by a few lines)
+ [x] Debug and solve delaying and blocking behavior of QFileSystemWatcher
+ [x] Fix missing auto-reload after clearing and reloading
+ [x] Fixing of delay in re-displaying log with QFileWatcher when DzBasicDialog are opened.

