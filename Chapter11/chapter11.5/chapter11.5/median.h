#pragma once
#ifndef MEDIAN_GUARD
#define MEDIAN_GUARD

#include <stdexcept>
#include <vector>
#include <algorithm>

using std::vector;
using std::domain_error;
using std::sort;

template <class T>
T median(vector<T> vec) {
	// we don't use ref here because we sort the vector
	// and we don't want this sort to affect the vector vec
	// from the caller
	typedef typename vector<T>::size_type size_vect;

	size_vect size = vec.size();

	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	size_vect mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

#endif