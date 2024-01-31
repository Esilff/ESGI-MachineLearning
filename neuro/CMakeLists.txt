set(NEURO_TARGET_NAME neuro)
set(NEURO_TARGET_SOURCES
        src/neuro.cpp
        src/algorithms/linearRegression.cpp
        src/data/ImageETL.cpp
)

option(NEURO_SHARED_BUILD "Use the Neuro lib in share mode." ON)

message(STATUS "Building Neuro as SHARED library.")
add_library(${NEURO_TARGET_NAME} SHARED ${NEURO_TARGET_SOURCES})

include(GenerateExportHeader)
generate_export_header(${NEURO_TARGET_NAME}
        BASE_NAME "neuro"
        EXPORT_MACRO_NAME "NEURO_API"
        EXPORT_FILE_NAME "export/neuro_export.hpp"
)

target_include_directories(${NEURO_TARGET_NAME}
        PUBLIC include
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/export
        PUBLIC ${CMAKE_SOURCE_DIR}/libs/stb
)

target_link_libraries(${NEURO_TARGET_NAME} PUBLIC eigen)
