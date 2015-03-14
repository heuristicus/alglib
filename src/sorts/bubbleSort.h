/**
 * @file   bubbleSort.h
 * @author Michal Staniaszek <michalst@kth.se>
 * @date   Sat Mar  7 17:22:29 2015
 * 
 * @brief  Headers for bubble sort.
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
	void bubbleSort(ArrayType *array, const int size);
	
	template<typename ArrayType, typename Compare>
	void bubbleSort(ArrayType *array, const int size, Compare comp);

	template<typename VectorType>
	void bubbleSort(std::vector<VectorType>& vec);

	template<typename VectorType, typename Compare>
	void bubbleSort(std::vector<VectorType>& vec, const Compare& comp);

    } // namespace sorts
} // namespace alglib

#include "impl/bubbleSort.hpp"

#endif // BUBBLESORT_H
