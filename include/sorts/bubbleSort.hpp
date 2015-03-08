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
    } // namespace sorts
} // namespace alglib

#endif // BUBBLESORT_H
