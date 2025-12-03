add_library(runer_lib
    runer.cpp
)

target_include_directories(runer_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(runer_lib
    PUBLIC
        calc_lib
        parse_lib
        print_lib
        date_structs_lib
)