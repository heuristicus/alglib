# Locate GTest
find_package(GTest REQUIRED)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
enable_testing()

# Include required directories
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(bubbleSort_test bubbleSort_test.cpp)
target_link_libraries(bubbleSort_test ${GTEST_LIBRARIES} pthread gtest_main alglib_sorts)
add_executable(insertionSort_test insertionSort_test.cpp)
target_link_libraries(insertionSort_test ${GTEST_LIBRARIES} pthread gtest_main alglib_sorts)

macro (create_test target)
  add_test (NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro (create_test)

create_test(bubbleSort_test)
create_test(insertionSort_test)