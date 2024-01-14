#==================== Defining project ====================

cmake_minimum_required(VERSION 3.22)
project(ESGI-MachineLearning VERSION 0.0.0 LANGUAGES C CXX)

#==================== Setting compiler flags ====================

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

#==================== Setting variables ====================

set(EXECUTABLE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}")

option(NEURO_SHARED_BUILD "Use the SeekR library in shared mode." ON)

#==================== Adding compile definitions ====================

add_compile_definitions(APP_NAME="${PROJECT_NAME}-${PROJECT_VERSION}")

add_compile_definitions(SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

#==================== Storing project name in txt file ====================
# This is done so that the run.bat can run seamlessly even if the project name is changed
# from the cmake file

file(WRITE "${CMAKE_BINARY_DIR}/project_name.txt" "${EXECUTABLE_NAME}/${PROJECT_NAME}")

#==================== Adding libs ====================

add_subdirectory(libs)

#==================== Adding personal code ====================

add_subdirectory(neuroCore)