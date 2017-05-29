#pragma once
#ifndef _GRADE_H_
#define _GRADE_H_

#include <vector>
#include <algorithm> // sort
#include <stdexcept> // exception

double grade(double, double, const std::vector<double>&);
double grade(double, double, double);

// pass a copy and not a ref because we sort the vector inside
// the fct
template <class T>
T median(std::vector<T> v) {
	typedef typename std::vector<T>::size_type vec_sz;
	vec_sz size = v.size();

	if (size == 0) 
		throw std::domain_error("median of an empty vector");

	std::sort(v.begin(), v.end());

	vec_sz mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

#endif