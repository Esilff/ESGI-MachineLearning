#==================== Adding executable ====================

add_executable(${PROJECT_NAME})

#==================== Targeting the include folder in root ====================

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

#==================== Using main.cpp as the source of the project ====================

target_sources(${PROJECT_NAME} PRIVATE main.cpp)

#==================== Adding project libraries ====================

#add_subdirectory(cpsWindow)

#==================== Targeting libraries in src ====================

#target_link_libraries(${PROJECT_NAME} glfw IMGUI cpsWindow)

#==================== Setting the target location at the root of the build directory ====================

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)