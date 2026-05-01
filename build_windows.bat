@echo off
setlocal

cmake -S . -B build -G "Visual Studio 17 2022" -A x64
if errorlevel 1 exit /b 1

cmake --build build --config Release
if errorlevel 1 exit /b 1

echo.
echo Built EXE at: build\Release\midnight_prototype.exe
powershell -Command "Compress-Archive -Path build\\Release\\midnight_prototype.exe -DestinationPath midnight_prototype_win.zip -Force"
if errorlevel 1 exit /b 1

echo Zip created: midnight_prototype_win.zip
