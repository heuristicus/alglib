SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include/sorts ${CMAKE_SOURCE_DIR})

# Not sure how to properly build a header-only library without including a dummy .cpp
add_library(alglib_sorts bubbleSort.cpp insertionSort.cpp)
