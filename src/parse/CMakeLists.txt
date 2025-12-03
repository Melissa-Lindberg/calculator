add_library(parse_lib
    parse.cpp
)

target_include_directories(parse_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
