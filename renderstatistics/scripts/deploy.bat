REM Deployment Script for DAZ Studio Plugins
REM ---
REM Script should be triggered by Post-Build Event inside Visual Studio.
REM For more information about such events see the following url:
REM https://msdn.microsoft.com/en-us/library/h7dhf0ty.aspx

echo "Deploying DAZ Studio plugin..."
copy /Y %1 "%DAZ_STUDIO%\plugins\"