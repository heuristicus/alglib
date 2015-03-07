/**
 * @file   quicksort_test.cpp
 * @author Michal Staniaszek <michalst@kth.se>
 * @date   Sat Mar  7 11:48:32 2015
 * 
 * @brief  Test for quicksort functions
 * 
 * 
 */
#include "search/quicksort.hpp"
#include <gtest/gtest.h>

/** 
 * Test positive numbers
 * 
 * @param SquareRootTest 
 * @param PositiveNos 
 * 
 * @return 
 */
TEST(testTest, positiveNos) { 
    ASSERT_EQ(3, testFunc(1, 1));
    ASSERT_EQ(7, testFunc(2, 3));
    ASSERT_EQ(10, testFunc(3, 4));
    ASSERT_EQ(13, testFunc(4,5));
}

/** 
 * Test negative numbers
 * 
 * @param testTest 
 * @param negativeNos 
 * 
 * @return 
 */
TEST(testTest, negativeNos) { 
    ASSERT_EQ(-5, testFunc(-2, -1));
    ASSERT_EQ(-8, testFunc(-3, -2));
}
