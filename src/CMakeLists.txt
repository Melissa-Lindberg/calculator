set(target calc)

add_subdirectory(calc)
add_subdirectory(parse)
add_subdirectory(print)
add_subdirectory(runer)
add_subdirectory(date_structs)

add_executable(${target} 
    main/main.cpp
)

target_link_libraries(${target}
    PRIVATE
        calc_lib
        parse_lib
        print_lib
        runer_lib
        date_structs_lib
        ${MY_MATH_LIBRARY}
)
