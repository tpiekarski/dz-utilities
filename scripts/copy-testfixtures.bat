REM Copy Script for test fixtures
REM ---
REM This Script should be triggered by Pre-Build Event inside Visual Studio.
REM For more information about such events please refer to the following url:
REM https://msdn.microsoft.com/en-us/library/h7dhf0ty.aspx

echo "Copying Test fixtures..."
copy /Y "%1" "%2"