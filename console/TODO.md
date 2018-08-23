dzUtilities::Console
---

#### TODO

##### Features
+ [ ] Add another color setting for the log text foreground color
+ [ ] Add buttons for previous and next search result (displayed on demand)
+ [ ] Add filter for the issuer of log messages
+ [ ] Add keyboard bindings for next and previous search result, highlight and reset
+ [ ] Create signal/slot connection between reloading log and highlighting search term
+ [ ] Implement search by regular expressions and add a checkbox for toggling
+ [ ] Improve speed of seeking to 0 when reloading log
+ [ ] Introduce a non-persistent search history
+ [ ] Introduce setting for case-sensitive search and search by whole search terms
+ [ ] Package and provide pre-compiled plugin library
+ [x] Add button for resetting search and highlight
+ [x] Add setting for the highlight color
+ [x] Add the possibility to search for keywords (forward and backward - starts over)
+ [x] Automatically redisplay the log when new messages have been written the log file
+ [x] Highlight search results (and a separate highlight button to highlight all results)
+ [x] Include input validation for the font size and provide fallback mechanism
+ [x] Make set up highlight color persistent
+ [x] Move from QPushButton for selecting highlight colors to DzColorPropertyWgt
+ [x] Remove most of previous signal-slot-based update connections
+ [x] Start searching for search term when return is pressed
+ [x] Withdraw settings when the settings dialog is canceled (highlight color)

##### UI
+ [ ] Disable search and highlight buttons when search term is empty
+ [x] Change or extend input widget for the font size with increase/decrease buttons (switch to QSpinBox)
+ [x] Lay out widgets in ConsoleSettingsDialog with QFormLayout
+ [x] Move control buttons into pane action menu

##### Legal issues
+ [x] Add legal disclaimer and Mozilla Public License

##### Development Improvements
+ [ ] Consider handling of possible dzError when adding DzColorProperty to DzColorPropertyWgt
+ [ ] Develop a CLI tool for deployment and replace batch scripts
+ [ ] Integrate cloud-based build tools like AppVeyor or Travis
+ [ ] Introduce namespace *utlis::console* to avoid future collisions
+ [ ] Migrate and integrate new logger library
+ [ ] Move processing of settings in ConsolePane::showSettings to ConsoleSettingsAction::executeAction
+ [ ] Refactor ConsoleSettings and ConsoleSettingsDialog (Restructure access to settings, remove unused methods and various other little improvements)
+ [ ] Validate search term by validator or inputMask
+ [x] Add another linter and static code analysis tool (cppcheck and ReSharper++ integrated)
+ [x] Cleaning constructor of ConsoleSettingsDialog
+ [x] Fix colliding constants header file in tests project
+ [x] Implement error handling inside menu actions when ConsolePane cannot be found
+ [x] Prefix all constants to avoid any future collisions with 3rd party constants
+ [x] Streamline file naming with prefix *console_* for avoiding filename collisions on the include path in the future
+ [x] Streamline naming of headers and source files to lowercased underscore
+ [x] Streamline naming with renaming ConsolePropertiesDialog to ConsoleSettingsDialog

##### Memory Improvements
+ [ ] Deallocate memory for settings in ConsoleSettings
+ [ ] Improve speed of highlighting by caching and only highlighting visible log
+ [x] At ConsolePane::showSettings deallocate memory for the ConsoleSettingsDialog
+ [x] Keep log file opened instead of opening/closing at every call to displayLog (see bugs:debug and solve delaying and blocking behavior)

##### Clean code
+ [ ] Check if const-qualified parameter should be defined in source as well as declared inside headers (Refers to inspection: Const-qualified parameter in a function declaration)
+ [ ] Consider static resolving of method calls in constructors (Refers to inspection: Call to a virtual function inside a constructor will be statically resolved)

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
+ [ ] Fix loosing new highlight color when ConsoleSettingsDialog is opened twice without changing color and when font size is changed and ConsoleLogBrowser::updateFontSize is called
+ [x] Debug and solve delaying and blocking behavior of QFileSystemWatcher
+ [x] Fix missing auto-reload after clearing and reloading
+ [x] Fix missing log path display in the settings dialog
+ [x] Fix VS Solution warning (Some of the properties associated with the solution could not be read).
+ [x] Fix warning about missing /MASCHINE argument during linking x86 library for testing
+ [x] Fixing of delay in re-displaying log with QFileWatcher when DzBasicDialog are opened.
