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

namespace alglib {
    namespace sorts {
	void bubbleSort(int *array, const int size);
	
	template<typename Compare>
	void bubbleSort(int *array, const int size, Compare comp){
	    if (size <= 0) {
		throw std::invalid_argument("Size must be > 0");
	    } else if (size == 1) {
		return; // if the size is 1, the array is already sorted
	    }
	
	    bool sorted;
	    do {
		// make the assumption that the array is sorted at the start of each
		// loop, and set it to false when out of order elements are swapped
		sorted = true;
		// only need to loop up to the n-1th element because each pair is
		// compared
		for (int i = 0; i < size - 1; i++) {
		    if (!comp(array[i], array[i+1])){
			int tmp = array[i];
			array[i] = array[i+1];
			array[i+1] = tmp;
			sorted = false;
		    }
		}
	    } while (!sorted);
	}
    } // namespace sorts
} // namespace alglib

#endif // BUBBLESORT_H
