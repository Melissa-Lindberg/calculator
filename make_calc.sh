# The -S switch sets the source directory, which must contain the CMakeLists.txt file.
# The -B switch sets the directory where the project will be built.
cmake -S . -B build 

cmake --build build