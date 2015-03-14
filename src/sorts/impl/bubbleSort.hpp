/**
 * @file   bubbleSort.hpp
 * @author Michal Staniaszek <michalst@kth.se>
 * @date   Sat Mar  7 17:21:48 2015
 * 
 * @brief  Implementation of bubble sort.
 * 
 * 
 */
#ifndef BUBBLESORT_IMPL_H
#define BUBBLESORT_IMPL_H

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

	/** 
	 * Do a bubble sort on the given array. The array is modified in place.
	 * The ordering is defined based on the function that is provided.
	 * 
	 * @param array The array to sort
	 * @param size The size of the array to sort. It is assumed that this is the
	 * actual size of the array to be sorted. A \p size too large may cause
	 * overflows, and a size too small will cause only the first \p size
	 * elements to be sorted. Negative arguments to size will throw an
	 * exception.
	 * @param comp Pointer to a function or functor which returns true if the first
	 * value takes priority over the second.
	 */
	template<typename ArrayType, typename Compare>
	void bubbleSort(ArrayType *array, const int size, Compare comp){
	    if (size <= 0) {
		throw std::invalid_argument("Size must be > 0");
	    } else if (size == 1) {
		return; // if the size is 1, the array is already sorted
	    }

	    // only need to loop up to the n-1th element because each pair is
	    // compared

	    for (int i = 0; i < size - 1; i++) {
		// After each pass the last element is in the correct place, so
		// don't need to check it again.
		for (int j = 0; j < size - 1 - i; j++) {
		    if (!comp(array[j], array[j + 1])){
			ArrayType tmp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = tmp;
		    }
		}
	    }
	}


	/** 
	 * Naive bubblesort which loops over the entire array each time,
	 * requiring an equality check to be done by the use of two comparisons
	 * per element.
	 * 
	 * @param array Array to sort
	 * @param size Size of the \p array
	 * @param comp A comparison function to compare elements of \p ArrayType
	 */
	template<typename ArrayType, typename Compare>
	void bubbleSort_naive(ArrayType *array, const int size, Compare comp){
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
		    // bool switchOrder = !comp(array[i+1], array[i]);
		    // Swap elements, but only if they are out of order, and not
		    // equal
		    if (outOfOrder && (outOfOrder != !comp(array[i+1], array[i]))){
			ArrayType tmp = array[i];
			array[i] = array[i+1];
			array[i+1] = tmp;
			sorted = false;
		    }
		}
	    } while (!sorted);
	}

	/** 
	 * Do a bubble sort on the given array. The array is modified in place.
	 * Uses \p operator<() as the default comparison, so the \p ArrayType should
	 * implement that.
	 * 
	 * @param array The array to sort
	 * @param size The size of the array to sort. It is assumed that this is the
	 * actual size of the array to be sorted. A \p size too large may cause
	 * overflows, and a size too small will cause only the first \p size
	 * elements to be sorted. Negative arguments to size will throw an
	 * exception.
	 */
	template<typename ArrayType>
	void bubbleSort(ArrayType *array, const int size){
	    bubbleSort(array, size, std::less<ArrayType>());
	}

	/** 
	 * Do a bubble sort on the given vector, using \p operator<() to define
	 * element ordering.
	 * 
	 * @param vec The vector to sort
	 */
	template<typename VectorType>
	void bubbleSort(std::vector<VectorType>& vec){
	    bubbleSort(&vec[0], (int)vec.size());
	}

	/** 
	 * Do a bubble sort on the given vector, using the specified function to
	 * define element ordering.
	 * 
	 * @param vec The vector to sort
	 * @param comp Pointer to a function or functor which returns true if the first
	 * value takes priority over the second.
	 */
	template<typename VectorType, typename Compare>
	void bubbleSort(std::vector<VectorType>& vec, const Compare& comp){
	    bubbleSort(&vec[0], (int)vec.size(), comp);
	}

    } // namespace sorts
} // namespace alglib

#endif // BUBBLESORT_IMPL_H




