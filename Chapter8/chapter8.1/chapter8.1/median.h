#pragma once
#ifndef MEDIAN_GUARD
#define MEDIAN_GUARD

#include <vector>
#include <algorithm>
#include <stdexcept>

template <class T>
double median(std::vector<T> vec) {
	// we don't use ref here because we sort the vector
	// and we don't want this sort to affect the vector vec
	// from the caller
	typedef typename std::vector<T>::size_type size_vect;

	size_vect size = vec.size();

	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	size_vect mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];

}


#endif