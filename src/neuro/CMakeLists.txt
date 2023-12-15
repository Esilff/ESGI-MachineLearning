set(NEURO_TARGET_NAME neuro)

set(NEURO_TARGET_SOURCES
        neuroApi.cpp
)

if (NEURO_SHARED_BUILD)
    add_library(${NEURO_TARGET_NAME} SHARED ${NEURO_TARGET_SOURCES})
else()
    add_library(${NEURO_TARGET_NAME} ${NEURO_TARGET_SOURCES})
endif ()

target_include_directories(${NEURO_TARGET_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include/neuro
)

include(GenerateExportHeader)
generate_export_header(${NEURO_TARGET_NAME}
    BASE_NAME "NeuroApi"
    EXPORT_MACRO_NAME "NEURO_API"
    EXPORT_FILE_NAME "export/neuroApi_export.hpp"
)

target_include_directories(${NEURO_TARGET_NAME}
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/export
)


