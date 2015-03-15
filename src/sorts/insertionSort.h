/**
 * @file   insertionSort.h
 * @author Michal Staniaszek <michalst@kth.se>
 * @date   Sun Mar 15 14:11:05 2015
 * 
 * @brief  
 * 
 * 
 */
#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <functional>
#include <iostream>

namespace alglib {
    namespace sorts {
	
	template<typename ArrayType>
	void insertionSort(ArrayType *array, const int& size);

	template<typename ArrayType, typename Compare>
	void insertionSort(ArrayType *array, const int& size, const Compare& comp);

    } // namespace sorts
} // namespace alglib

#include "impl/insertionSort.hpp"

#endif // INSERTIONSORT_H
