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
+ [ ] Streamline naming of headers and source files to lowercased underscore
+ [ ] Replace setter by reference in ConsoleSettings with usual setters
+ [ ] Implement error handling inside menu actions when ConsolePane can not be found
+ [ ] Integrate cloud-based build tools like AppVeyor or Travis

#### Bugs
+ [ ] Fix reload bug for manual reload
+ [ ] Fix initial log display bug not showing the end of file (off by a few lines)
+ [ ] Fix missing auto-reload after clearing