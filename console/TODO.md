dzUtilities::Console
---

#### TODO

##### Features
+ [x] Automatically redisplay the log when new messages have been written the log file
+ [x] Remove most of previous signal-slot-based update connections
+ [ ] Add the possibility to search for keywords forward and backward
+ [ ] Highlight search results
+ [ ] Add filter for the issuer of log messages
+ [ ] Improve speed of seeking to 0 when reloading log

##### UI
+ [x] Move control buttons into pane action menu

##### Legal issues
+ [ ] Add legal disclaimer and Mozilla Public License

##### Development Improvements
+ [x] Streamline naming of headers and source files to lowercased underscore
+ [x] Implement error handling inside menu actions when ConsolePane cannot be found
+ [x] Add another linter and static code analysis tool (cppcheck and ReSharper++ integrated)
+ [ ] Integrate cloud-based build tools like AppVeyor or Travis

##### Memory Improvements
+ [x] Keep log file opened instead of opening/closing at every call to displayLog
      (see bugs:debug and solve delaying and blocking behavior)

##### Clean code
+ [ ] Consider static resolving of method calls in constructors
      (Refers to inspection: Call to a virtual function inside a constructor will be statically resolved)
+ [ ] Check if const-qualified parameter should be defined in source as well as declared inside headers
      (Refers to inspection: Const-qualified parameter in a function declaration)

#### Bugs
+ [x] Debug and solve delaying and blocking behavior of QFileSystemWatcher
      (Loading and rendering with a lot of logged lines delays operation and blocks UI.
       The reason for this blocking behavior is that every fileChanges signal calls
       reloadLog which opens and closes the log file with the method displayLog.)
+ [ ] Fix initial log display bug sometimes not showing the end of file (off by a few lines)
+ [x] Fix missing auto-reload after clearing and reloading
      (When removing the file the QFileWatcher stops watching for changes and at
       this moment it is not possible to restart the watching once more.)
+ [x] Debugging and probably fixing of delay in redisplaying log with QFileWatcher
      when DzBasicDialog are opened.
