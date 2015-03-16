/**
 * @file   insertionSort.hpp
 * @author Michal Staniaszek <michalst@kth.se>
 * @date   Sun Mar 15 14:10:49 2015
 * 
 * @brief  
 * 
 * 
 */
#ifndef INSERTIONSORT_IMPL_H
#define INSERTIONSORT_IMPL_H

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
	
	template<typename ArrayType>
	void insertionSort(ArrayType *array, const int& size) {
	    insertionSort(array, size, std::less<ArrayType>());
	}
    

	template<typename ArrayType, typename Compare>
	void insertionSort(ArrayType *array, const int& size, const Compare& comp) {
	    if (size <= 0) {
		throw std::invalid_argument("Size must be > 0");
	    } else if (size == 1) {
		return; // if the size is 1, the array is already sorted
	    }
	    
	    // Loop over all elements in the array, starting from the second.
	    // The first is already in the sorted portion.
	    for (int i = 1; i < size; i++) {
		print_arr(array, size);
		// For each element, compare it to preceding elements in the
		// array until an element is found which has priority over the
		// element being checked.
		int current = i;
		while (comp(array[current], array[current - 1]) && current > 0) {
		    std::cout << "Compare [" << current << "]: " << array[current]
			      << " against [" << current - 1 << "]: " << array[current - 1]
			      << " is true" << std::endl;
		    // if the elements are not in order, swap them.
		    ArrayType tmp = array[current - 1];
		    array[current - 1] = array[current];
		    array[current] = tmp;
		    current--;
		}
		// update the check location to be the element before the one
		// being checked.

	    }
	}

	template<typename ArrayType>
	void insertionSort(std::vector<ArrayType>& vec) {
	    insertionSort(&vec[0], vec.size(), std::less<ArrayType>());
	}
    

	template<typename ArrayType, typename Compare>
	void insertionSort(std::vector<ArrayType>& vec, const Compare& comp) {
	    insertionSort(&vec[0], vec.size(), comp);
	}

    } // namespace sorts
} // namespace alglib

#endif // INSERTIONSORT_IMPL_H
