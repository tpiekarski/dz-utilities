REM Deployment Script for DAZ Studio Plugins (Including resources)
REM ---
REM First argument is the target plugin library and the second argument is the
REM resource directoy. This Script should be triggered by Post-Build Event
REM inside Visual Studio. For more information about such events please refer
REM to the following url: https://msdn.microsoft.com/en-us/library/h7dhf0ty.aspx

echo "Deploying DAZ Studio plugin and resources..."
copy /Y %1 "%DAZ_STUDIO%\plugins\"
mkdir "%DAZ_STUDIO%\plugins\renderstatistics"
copy /Y %2\*.* "%DAZ_STUDIO%\plugins\renderstatistics\"