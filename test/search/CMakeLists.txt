# Locate GTest
find_package(GTest REQUIRED)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Include required directories
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(rtest quicksort_test.cpp)
target_link_libraries(rtest ${GTEST_LIBRARIES} pthread gtest_main runTests)