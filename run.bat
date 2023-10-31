@echo off

color

del /Q "build\*"

for /D %%I in ("build\*") do rd /S /Q "%%I"

echo Building CMake project

cmake -B ./build -S ./ -G "MinGW Makefiles"

cd build

make

for /f "usebackq delims=" %%I in ("project_name.txt") do (
    set "string=%%I"
)

for /f "tokens=1,2 delims=/" %%A in ("%string%") do (
    set "PROJECT_NAME=%%A"
    set "EXEC_NAME=%%B"
)

echo Running %PROJECT_NAME%

%EXEC_NAME%