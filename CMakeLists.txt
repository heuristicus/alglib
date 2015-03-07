CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project("alglib")

enable_testing()

# Process the CMakeLists.txt in these directories
add_subdirectory(src/sorts)
add_subdirectory(test/sorts)