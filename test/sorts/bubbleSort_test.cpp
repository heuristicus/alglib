/**
 * @file   bubbleSort_test.cpp
 * @author Michal Staniaszek <michalst@kth.se>
 * @date   Sat Mar  7 20:29:14 2015
 * 
 * @brief  Tests for sorts::bubbleSort implementation
 * 
 * Tests for Bubblesort.
 */
#include "sorts/bubbleSort.hpp"
#include <gtest/gtest.h>


namespace tests {
    namespace sorts {
        /** 
         * Test that bubbleSort() works for the positive numbers
         * 
         */
	TEST(BubbleSortTest, positiveNos) { 
	    int unsorted[] = {10, 5, 2, 3, 1, 4, 9, 6, 7, 8};
	    int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	    int size = sizeof(unsorted) / sizeof(*unsorted);
    
	    alglib::sorts::bubbleSort(unsorted, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}


        /** 
         * Test that bubbleSort() works with negative numbers
         * 
         */
	TEST(BubbleSortTest, negativeNos) { 
	    int unsorted[] = {-5, -2, -3, -1, -4, -9, -6, -7, -8, -10};
	    int sorted[] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1};

	    int size = sizeof(unsorted) / sizeof(*unsorted);
    
	    alglib::sorts::bubbleSort(unsorted, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

        /** 
         * Test that bubbleSort() has the expected behaviour when \p array has a single
         * element
         *
         */
	TEST(BubbleSortTest, edgeCases_oneElement) { 
	    int unsorted[] = {2};
	    int sorted[] = {2};

	    int size = sizeof(unsorted) / sizeof(*unsorted);
    
	    alglib::sorts::bubbleSort(unsorted, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

        /** 
         * Test that bubbleSort() has the expected behaviour when \p array has two
         * elements
         * 
         */
	TEST(BubbleSortTest, edgeCases_twoElement) { 
	    int unsorted1[] = {4, 2};
	    int unsorted2[] = {2, 4};
	    int sorted[] = {2, 4};

	    int size = sizeof(unsorted1) / sizeof(*unsorted1);
    
	    alglib::sorts::bubbleSort(unsorted1, size);
	    alglib::sorts::bubbleSort(unsorted2, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted1[i]);
		ASSERT_EQ(sorted[i], unsorted2[i]);
	    }
	}


        /** 
         * Test that bubbleSort() has the expected behaviour when the \p size
         * given is smaller than the length of \p array. We expect that the
         * first \p size elements in the array to be correctly sorted.
         * 
         */
	TEST(BubbleSortTest, edgeCases_smallerSize) { 
	    int unsorted[] = {10, 5, 2, 3, 1, 4, 9, 6, 7, 8};
	    int sorted[] = {1, 2, 3, 4, 5, 10}; // only the first 6 elements are sorted

	    int size = sizeof(unsorted) / sizeof(*unsorted) - 4;
    
	    alglib::sorts::bubbleSort(unsorted, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(unsorted[i], sorted[i]);
	    }
	}

        /** 
         * Test that bubbleSort() has the expected behaviour when the \p size given is
         * negative
         *
         */
	TEST(BubbleSortTest, edgeCases_negativeSize) { 
	    int unsorted[] = {4, 2, 3, 5, 1, 7};

	    ASSERT_THROW(alglib::sorts::bubbleSort(unsorted, -1), std::invalid_argument);
	    ASSERT_THROW(alglib::sorts::bubbleSort(unsorted, 0), std::invalid_argument);
	}

	/**
	 * Test that bubbleSort() has the expected behaviour when given a
	 * comparison function which orders smallest elements first.
	 */
	TEST(BubbleSortTest, func_smallestFirst) {
	    int unsorted[] = {4, 2, 3, 5, 1, 7};
	    int sorted[] = {1, 2, 3, 4, 5, 7};
	    int size = sizeof(unsorted) / sizeof(*unsorted);

	    auto comp = [](int a, int b) -> bool {return a < b;};
	    alglib::sorts::bubbleSort(unsorted, size, comp);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(unsorted[i], sorted[i]);
	    }
	}

	/**
	 * Test that bubbleSort() has the expected behaviour when given a
	 * comparison function which orders largest elements first.
	 */
	TEST(BubbleSortTest, func_biggestFirst) {
	    int unsorted[] = {4, 2, 3, 5, 1, 7};
	    int sorted[] = {7, 5, 4, 3, 2, 1};
	    int size = sizeof(unsorted) / sizeof(*unsorted);

	    auto comp = [](int a, int b) -> bool {return a > b;};
	    alglib::sorts::bubbleSort(unsorted, size, comp);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(unsorted[i], sorted[i]);
	    }
	}
	
    } // namespace sorts
} // namespace tests
