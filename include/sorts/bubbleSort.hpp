/**
 * @file   bubbleSort.hpp
 * @author Michal Staniaszek <michalst@kth.se>
 * @date   Sat Mar  7 17:21:48 2015
 * 
 * @brief  Headers for bubble sort.
 * 
 * 
 */
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <stdexcept>
#include <functional>
#include <vector>
#include <iostream>

namespace alglib {
    namespace sorts {

	template<typename ArrayType>
	void print_arr(const ArrayType *array, const int size){
	    std::cout << "[";
	    int i;
	    for (i = 0; i < size - 1; i++) {
		std::cout << array[i] << ", ";
	    }
	    std::cout << array[i] << "]" << std::endl;
	}
	
	template<typename ArrayType, typename Compare>
	void bubbleSort(ArrayType *array, const int size, Compare comp){
	    if (size <= 0) {
		throw std::invalid_argument("Size must be > 0");
	    } else if (size == 1) {
		return; // if the size is 1, the array is already sorted
	    }
	
	    bool sorted;
	    do {
		print_arr(array, size); 
		// make the assumption that the array is sorted at the start of each
		// loop, and set it to false when out of order elements are swapped
		sorted = true;
		// only need to loop up to the n-1th element because each pair is
		// compared
		for (int i = 0; i < size - 1; i++) {
		    std::cout << "compare " << array[i]
			      << " and " << array[i+1]
			      << ": (i,i+1) -> " << !comp(array[i], array[i+1])
			      << ", (i+1,i) -> " << !comp(array[i+1], array[i])
			      << std::endl;
		    
		    // True if array[i] should come before array[i+1]
		    bool outOfOrder = !comp(array[i], array[i+1]);
		    // True if array[i+1] should come before array[i] - if this
		    // is the same as outOfOrder, the elements are equal.
		    bool switchOrder = !comp(array[i+1], array[i]);
		    // Swap elements, but only if they are out of order, and not
		    // equal
		    if (outOfOrder && (outOfOrder != switchOrder)){
			ArrayType tmp = array[i];
			array[i] = array[i+1];
			array[i+1] = tmp;
			sorted = false;
		    }
		}
	    } while (!sorted);
	}

	template<typename ArrayType>
	void bubbleSort(ArrayType *array, const int size){
	    bubbleSort(array, size, std::less<ArrayType>());
	}

	template<typename VectorType>
	void bubbleSort(std::vector<VectorType>& vec){
	    bubbleSort(&vec[0], (int)vec.size());
	}

	template<typename VectorType, typename Compare>
	void bubbleSort(std::vector<VectorType>& vec, const Compare& comp){
	    bubbleSort(&vec[0], (int)vec.size(), comp);
	}

    } // namespace sorts
} // namespace alglib

#endif // BUBBLESORT_H
