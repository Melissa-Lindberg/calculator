cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME calc)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
    -Wall 
    -Wextra 
    -Werror 
    -pedantic
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

set(MY_MATH_LIBRARY my_math)

FetchContent_Declare(
    ${MY_MATH_LIBRARY}
    GIT_REPOSITORY https://github.com/Melissa-Lindberg/math_lib.git
    GIT_TAG main
)
FetchContent_MakeAvailable(${MY_MATH_LIBRARY})

add_subdirectory(src)
