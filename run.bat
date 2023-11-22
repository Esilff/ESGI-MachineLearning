@echo off

color

@cls

echo Building CMake project

cmake -B ./build -S ./ -G "MinGW Makefiles"

cmake --build ./build --target all -- -j12

for /f "usebackq delims=" %%I in ("./build/project_name.txt") do (
    set "string=%%I"
)

for /f "tokens=1,2 delims=/" %%A in ("%string%") do (
    set "PROJECT_NAME=%%A"
    set "EXEC_NAME=%%B"
)

echo Running %PROJECT_NAME%

.\build\%EXEC_NAME%