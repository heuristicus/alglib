SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include/sorts)

add_library(alglib_sorts bubbleSort.cpp)