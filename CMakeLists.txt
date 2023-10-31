cmake_minimum_required(VERSION 3.12)

project(ESGI-MachineLearning VERSION 0.0.0)

set(EXECUTABLE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}")

file(WRITE "${CMAKE_BINARY_DIR}/project_name.txt" "${EXECUTABLE_NAME}/${PROJECT_NAME}")

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)
