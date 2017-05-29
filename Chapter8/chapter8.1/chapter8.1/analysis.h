#pragma once
#ifndef _ANALYSIS_H_
#define _ANALYSIS_H_

#include <string>
#include <vector>
#include "Student_info.h"
#include "median.h"

// Answer to Q8.1 (this time we use a template function => defined in .h)
template <class Fct>
double analysis(const std::vector<Student_info>& s, Fct grading_method) {
	std::vector<double> grades;
	transform(s.begin(), s.end(), back_inserter(grades), grading_method);
	return median(grades);
}

template <class Fct>
void write_analysis(std::ostream& out,
	const std::string& name,
	Fct grading_method,
	const std::vector<Student_info>& did,
	const std::vector<Student_info>& didnt) {

	out << name << ": median(did) = " << analysis(did, grading_method) <<
		", median(didnt) = " << analysis(didnt, grading_method) << endl;
}

#endif // !_ANALYSIS_H_
