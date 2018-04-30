dzUtilities::Console
---

#### TODO

##### Features
+ [x] Automatically redisplay the log when new messages have been written the log file
+ [x] Remove most of previous signal-slot-based update connections
+ [ ] Add the possibility to search for keywords forward and backward
+ [ ] Highlight search results
+ [ ] Add filter for the issuer of log messages

##### UI
+ [x] Move control buttons into pane action menu

##### Legal issues
+ [ ] Add legal disclaimer and Mozilla Public License

##### Development Improvements
+ [x] Streamline naming of headers and source files to lowercased underscore
+ [x] Implement error handling inside menu actions when ConsolePane can not be found
+ [ ] Add another linter and static code analysis tool (cppcheck already integrated)
+ [ ] Integrate cloud-based build tools like AppVeyor or Travis

#### Bugs
+ [ ] Debug and solve delaying and blocking behavior of QFileSystemWatcher
      (Loading and rendering with a lot of logged lines delays operation and blocks UI)
+ [ ] Fix initial log display bug not showing the end of file (off by a few lines)
+ [ ] Fix missing auto-reload after clearing and reloading
      (When removing the file the QFileWatcher stops watching for changes and at
       this moment it is not possible to restart the watching once more.)
+ [ ] Debugging and propably fixing of delay in redisplaying log with QFileWatcher
      when DzBasicDialogs are opened.
