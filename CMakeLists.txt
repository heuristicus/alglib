CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project("alglib")

# Process the CMakeLists.txt in these directories
add_subdirectory(src/search)
add_subdirectory(test/search)

message(${PROJECT_BINARY_DIR})