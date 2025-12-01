set(target ${PROG_LIBRARY})

file(GLOB hdrs "*.h")
file(GLOB srcs "*.cpp")

add_library(${target} 
    STATIC 
        ${srcs} ${hdrs}
)

target_include_directories(${target}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)