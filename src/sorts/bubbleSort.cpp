/**
 * @file   bubbleSort.cpp
 * @author Michal Staniaszek <michalst@kth.se>
 * @date   Sat Mar  7 17:22:29 2015
 * 
 * @brief  Bubble sort. Simple and inefficient.
 * 
 */

#include "bubbleSort.hpp"
namespace alglib {
    namespace sorts {
    
	/** 
	 * Do a bubble sort on the given array of integers. The array is modified in
	 * place. The lowest element will be placed in the first index.
	 * 
	 * @param array The array to sort
	 * @param size The size of the array to sort. It is assumed that this is the
	 * actual size of the array to be sorted. A \p size too large may cause
	 * overflows, and a size too small will cause only the first \p size
	 * elements to be sorted. Negative arguments to size will throw an
	 * exception.
	 */
	void bubbleSort(int *array, const int size){
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
		    if (!(array[i] < array[i+1])){
			int tmp = array[i];
			array[i] = array[i+1];
			array[i+1] = tmp;
			sorted = false;
		    }
		}
	    } while (!sorted);
	}

	/** 
	 * Do a bubble sort on the given array of integers. The array is modified in
	 * place. The ordering is defined based on the function that is provided.
	 * 
	 * @param array The array to sort
	 * @param size The size of the array to sort. It is assumed that this is the
	 * actual size of the array to be sorted. A \p size too large may cause
	 * overflows, and a size too small will cause only the first \p size
	 * elements to be sorted. Negative arguments to size will throw an
	 * exception.
	 * @param comp Pointer to a function or functor which returns true if the first
	 * integer takes priority over the second.
	 */
	template<typename Compare>
	void bubbleSort(int *array, const int size, Compare comp);

    } // namespace sorts

} // namespace alglib
