SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include/search)
add_library(runTests quicksort.cpp)
set_target_properties(runTests PROPERTIES
  LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)