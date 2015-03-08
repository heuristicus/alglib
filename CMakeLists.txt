CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project("alglib")

enable_testing()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

# Process the CMakeLists.txt in these directories
add_subdirectory(src/sorts)
add_subdirectory(test/sorts)