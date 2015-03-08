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
	void bubbleSort(ArrayType *array, const int size);
	
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
	void bubbleSort(ArrayType *array, const int size, Compare comp);


	/** 
	 * Do a bubble sort on the given vector, using \p operator<() to define
	 * element ordering.
	 * 
	 * @param vec The vector to sort
	 */
	template<typename VectorType>
	void bubbleSort(std::vector<VectorType>& vec);

	/** 
	 * Do a bubble sort on the given vector, using the specified function to
	 * define element ordering.
	 * 
	 * @param vec The vector to sort
	 * @param comp Pointer to a function or functor which returns true if the first
	 * value takes priority over the second.
	 */
	template<typename VectorType, typename Compare>
	void bubbleSort(std::vector<VectorType>& vec, const Compare& comp);
	
    } // namespace sorts

} // namespace alglib
