set(target main)

add_subdirectory(calc)
add_subdirectory(parse)
add_subdirectory(print)
add_subdirectory(runer)
add_subdirectory(date_strucrs)

add_executable(${target} 
    main/main.cpp
)

target_link_libraries(${target}
    PRIVATE
        calc_lib
        parse_lib
        print_lib
        runer_lib
        date_strucrs_lib
        ${MY_MATH_LIBRARY}
)
