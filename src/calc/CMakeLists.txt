add_library(calc_lib
    calc.cpp
)

target_include_directories(calc_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(calc_lib
    PUBLIC
        date_structs_lib
        ${MY_MATH_LIBRARY}
)
