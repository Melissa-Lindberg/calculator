set(target main)

file(GLOB hdrs "*.h")
file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs} ${hdrs})

target_link_libraries(${target} 
    PRIVATE
        ${PROG_LIBRARY}
)
