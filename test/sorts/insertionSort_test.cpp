/**
 * @file   insertionSort_test.cpp
 * @author Michal Staniaszek <michalst@kth.se>
 * @date   Sat Mar  7 20:29:14 2015
 * 
 * @brief  Tests for sorts::bubbleSort implementation
 * 
 * Tests for Bubblesort.
 */
#include "sorts/insertionSort.h"
#include <iostream>
#include <gtest/gtest.h>


namespace tests {
    namespace sorts {
	
        /** 
	 * Tests that insertionSort() works for the positive numbers
         * 
         */
	TEST(InsertionSortTest, positiveNos) { 
	    int unsorted[] = {10, 5, 2, 3, 1, 4, 9, 6, 7, 8};
	    int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	    int size = sizeof(unsorted) / sizeof(*unsorted);
    
	    alglib::sorts::insertionSort(unsorted, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}


        /** 
         * Test that insertionSort() works with negative numbers
         * 
         */
	TEST(InsertionSortTest, negativeNos) { 
	    int unsorted[] = {-5, -2, -3, -1, -4, -9, -6, -7, -8, -10};
	    int sorted[] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1};

	    int size = sizeof(unsorted) / sizeof(*unsorted);
    
	    alglib::sorts::insertionSort(unsorted, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

        /** 
	 * Tests that insertionSort() works when there are elements with the same
	 * value in the array
         * 
         */
	TEST(InsertionSortTest, sameValue) { 
	    int unsorted[] = {10, 5, 2, 3, 1, 4, 9, 6, 7, 7, 5, 8};
	    int sorted[] = {1, 2, 3, 4, 5, 5, 6, 7, 7, 8, 9, 10};

	    int size = sizeof(unsorted) / sizeof(*unsorted);
    
	    alglib::sorts::insertionSort(unsorted, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}	

        /** 
         * Test that insertionSort() has the expected behaviour when \p array has a single
         * element
         *
         */
	TEST(InsertionSortTest, edgeCases_oneElement) { 
	    int unsorted[] = {2};
	    int sorted[] = {2};

	    int size = sizeof(unsorted) / sizeof(*unsorted);
    
	    alglib::sorts::insertionSort(unsorted, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

        /** 
         * Test that insertionSort() has the expected behaviour when \p array has two
         * elements
         * 
         */
	TEST(InsertionSortTest, edgeCases_twoElement) { 
	    int unsorted1[] = {4, 2};
	    int unsorted2[] = {2, 4};
	    int sorted[] = {2, 4};

	    int size = sizeof(unsorted1) / sizeof(*unsorted1);
    
	    alglib::sorts::insertionSort(unsorted1, size);
	    alglib::sorts::insertionSort(unsorted2, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted1[i]);
		ASSERT_EQ(sorted[i], unsorted2[i]);
	    }
	}


        /** 
         * Test that insertionSort() has the expected behaviour when the \p size
         * given is smaller than the length of \p array. We expect that the
         * first \p size elements in the array to be correctly sorted.
         * 
         */
	TEST(InsertionSortTest, edgeCases_smallerSize) { 
	    int unsorted[] = {10, 5, 2, 3, 1, 4, 9, 6, 7, 8};
	    int sorted[] = {1, 2, 3, 4, 5, 10}; // only the first 6 elements are sorted

	    int size = sizeof(unsorted) / sizeof(*unsorted) - 4;
    
	    alglib::sorts::insertionSort(unsorted, size);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(unsorted[i], sorted[i]);
	    }
	}

        /** 
         * Test that insertionSort() has the expected behaviour when the \p size given is
         * negative
         *
         */
	TEST(InsertionSortTest, edgeCases_negativeSize) { 
	    int unsorted[] = {4, 2, 3, 5, 1, 7};

	    ASSERT_THROW(alglib::sorts::insertionSort(unsorted, -1), std::invalid_argument);
	    ASSERT_THROW(alglib::sorts::insertionSort(unsorted, 0), std::invalid_argument);
	}

	/**
	 * Test that insertionSort() has the expected behaviour when given a
	 * comparison lambda function which orders smallest elements first.
	 */
	TEST(InsertionSortTest, lambdaFunc_smallestFirst) {
	    int unsorted[] = {4, 2, 3, 5, 1, 7};
	    int sorted[] = {1, 2, 3, 4, 5, 7};
	    int size = sizeof(unsorted) / sizeof(*unsorted);

	    auto comp = [](const int& a, const int& b) -> bool {return a < b;};
	    alglib::sorts::insertionSort(unsorted, size, comp);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(unsorted[i], sorted[i]);
	    }
	}

	/**
	 * Test that insertionSort() has the expected behaviour when given a
	 * comparison lambda function which orders largest elements first.
	 */
	TEST(InsertionSortTest, lambdaFunc_biggestFirst) {
	    int unsorted[] = {4, 2, 3, 5, 1, 7};
	    int sorted[] = {7, 5, 4, 3, 2, 1};
	    int size = sizeof(unsorted) / sizeof(*unsorted);

	    auto comp = [](const int& a, const int& b) -> bool {return a > b;};
	    alglib::sorts::insertionSort(unsorted, size, comp);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

	/**
	 * Test that insertionSort() has the expected behaviour when given a
	 * comparison functor which orders smallest elements first.
	 */
	TEST(InsertionSortTest, functor_smallestFirst) {
	    int unsorted[] = {4, 2, 3, 5, 1, 7};
	    int sorted[] = {1, 2, 3, 4, 5, 7};
	    int size = sizeof(unsorted) / sizeof(*unsorted);

	    struct compSmallestFirst {
		bool operator()(const int& a, const int& b) const {return a < b;}
	    } compSF;

	    alglib::sorts::insertionSort(unsorted, size, compSF);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

	/**
	 * Test that insertionSort() has the expected behaviour when given a
	 * comparison functor which orders largest elements first.
	 */
	TEST(InsertionSortTest, functor_biggestFirst) {
	    int unsorted[] = {4, 2, 3, 5, 1, 7};
	    int sorted[] = {7, 5, 4, 3, 2, 1};
	    int size = sizeof(unsorted) / sizeof(*unsorted);

	    struct compBiggestFirst {
		bool operator()(const int& a, const int& b) const {return a > b;}
	    } compBF;
	    
	    alglib::sorts::insertionSort(unsorted, size, compBF);

	    for (int i = 0; i < size; i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

	/**
	 * Test that the std::vector version of insertionSort() works with a built
	 * in type with the standard comparison operation on that type.
	 */
	TEST(InsertionSortTest, vector_basic) {
	    std::vector<int> unsorted = {4, 2, 3, 5, 1, 7};
	    std::vector<int> sorted = {1, 2, 3, 4, 5, 7};

	    alglib::sorts::insertionSort<int>(unsorted);

	    for (size_t i = 0; i < unsorted.size(); i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}
	
	/**
	 * Test that the std::vector version of insertionSort() works with a built
	 * in type using a functor.
	 */
	TEST(InsertionSortTest, vector_functorBuiltin) {
	    std::vector<int> unsorted = {4, 2, 3, 5, 1, 7};
	    std::vector<int> sorted = {1, 2, 3, 4, 5, 7};

	    struct compSmallestFirst {
		bool operator()(const int& a, const int& b) const {return a < b;}
	    } compSF;
	    
	    alglib::sorts::insertionSort(unsorted, compSF);

	    for (size_t i = 0; i < unsorted.size(); i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

	/**
	 * Test that the std::vector version of insertionSort() works with a built
	 * in type using a lambda function.
	 */
	TEST(InsertionSortTest, vector_lambdaBuiltin) {
	    std::vector<int> unsorted = {4, 2, 3, 5, 1, 7};
	    std::vector<int> sorted = {1, 2, 3, 4, 5, 7};

	    auto comp = [](const int& a, const int& b) -> bool {return a < b;};

	    alglib::sorts::insertionSort(unsorted, comp);

	    for (size_t i = 0; i < unsorted.size(); i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

	/** 
	 * Simple class for testing generic functionality
	 * 
	 * @param _a 
	 */
	class CustomClass {
	public:
	    CustomClass(int _a) : a(_a) {}
	    /// An integer to use to compare different objects of the type.
	    int a;

	    /** 
	     * 
	     * 
	     * @param other The CustomClass object with which to compare this one
	     * 
	     * @return True if the value of CustomClass::a of \p other is larger
	     * than the one for this object
	     */
	    bool operator<(const CustomClass& other) const {
		return a > other.a;
	    }

	    /** 
	     * 
	     * 
	     * @param other The CustomClass object with which to compare this one
	     * 
	     * @return True if CustomClass::a for the other class is equal to
	     * the one of this object
	     */
	    bool operator==(const CustomClass& other) const {
		return a == other.a;
	    }

	    friend std::ostream& operator<<(std::ostream& os, const CustomClass& c);
	};

	std::ostream& operator<<(std::ostream& os, const CustomClass& c){
	    os << c.a;
	    return os;
	}
	
        /**
	 * Test that the std::vector version of insertionSort() works with a custom
	 * type and using \p operator<() implemented within that class.
	 */
	TEST(InsertionSortTest, vector_basicCustomClass) {
	    CustomClass one(1);
	    CustomClass two(2);
	    CustomClass three(3);
	    CustomClass four(4);
	    CustomClass five(5);
	    CustomClass six(6);

	    std::vector<CustomClass> unsorted;
	    unsorted.push_back(three);
	    unsorted.push_back(one);
	    unsorted.push_back(four);
	    unsorted.push_back(six);
	    unsorted.push_back(two);
	    unsorted.push_back(five);
	    
	    std::vector<CustomClass> sorted;
	    sorted.push_back(six);
	    sorted.push_back(five);
	    sorted.push_back(four);
	    sorted.push_back(three);
	    sorted.push_back(two);
	    sorted.push_back(one);
	    
	    alglib::sorts::insertionSort(unsorted);

	    for (size_t i = 0; i < unsorted.size(); i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

	/**
	 * Test that the std::vector version of insertionSort() works with a built
	 * in type using a functor.
	 */
	TEST(InsertionSortTest, vector_functorCustomClass) {
	    CustomClass one(1);
	    CustomClass two(2);
	    CustomClass three(3);
	    CustomClass four(4);
	    CustomClass five(5);
	    CustomClass six(6);

	    std::vector<CustomClass> unsorted;
	    unsorted.push_back(three);
	    unsorted.push_back(one);
	    unsorted.push_back(four);
	    unsorted.push_back(six);
	    unsorted.push_back(two);
	    unsorted.push_back(five);
	    
	    std::vector<CustomClass> sorted;
	    sorted.push_back(one);
	    sorted.push_back(two);
	    sorted.push_back(three);
	    sorted.push_back(four);
	    sorted.push_back(five);
	    sorted.push_back(six);
	    
	    struct compSmallestFirst {
		bool operator()(const CustomClass& one, const CustomClass& two) const {
		    return one.a < two.a;
		}
	    } compSF;
	    
	    alglib::sorts::insertionSort(unsorted, compSF);

	    for (size_t i = 0; i < unsorted.size(); i++) {
		ASSERT_EQ(sorted[i], unsorted[i]);
	    }
	}

	/**
	 * Test that the std::vector version of insertionSort() works with a built
	 * in type using a functor.
	 */
	TEST(InsertionSortTest, vector_lambdaCustomClass) {
	    CustomClass one(1);
	    CustomClass two(2);
	    CustomClass three(3);
	    CustomClass four(4);
	    CustomClass five(5);
	    CustomClass six(6);

	    std::vector<CustomClass> unsorted;
            unsorted.push_back(three);
	    unsorted.push_back(one);
	    unsorted.push_back(four);
	    unsorted.push_back(six);
	    unsorted.push_back(two);
	    unsorted.push_back(five);
	    
	    std::vector<CustomClass> sorted;
            sorted.push_back(one);
	    sorted.push_back(two);
	    sorted.push_back(three);
	    sorted.push_back(four);
	    sorted.push_back(five);
	    sorted.push_back(six);
				    
	    auto comp = [](const CustomClass& one, const CustomClass& two){
		return one.a < two.a;
	    };
	    
	    alglib::sorts::insertionSort(unsorted, comp);

	    for (size_t i = 0; i < unsorted.size(); i++) {
		ASSERT_EQ(unsorted[i], sorted[i]);
	    }
	}
	
    } // namespace sorts
} // namespace tests
