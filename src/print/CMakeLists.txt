add_library(print_lib INTERFACE)

target_include_directories(print_lib
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
