set(NEURO_CORE_TARGET_NAME neuroCore)

set(NEURO_CORE_TARGET_SOURCE main.cpp src/neuroApi.cpp)

if(NEURO_SHARED_BUILD)
    add_library(${NEURO_CORE_TARGET_NAME} SHARED ${NEURO_CORE_TARGET_SOURCE})
else ()
    add_library(${NEURO_CORE_TARGET_NAME} STATIC ${NEURO_CORE_TARGET_SOURCE})
endif ()

include(GenerateExportHeader)
generate_export_header(${NEURO_CORE_TARGET_NAME}
        BASE_NAME "NeuroCore"
        EXPORT_MACRO_NAME "NEURO_CORE_API"
        EXPORT_FILE_NAME "export/neurocore_export.hpp"
)

target_include_directories(${NEURO_CORE_TARGET_NAME}
        PUBLIC include
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/export
)