#pragma once
#ifndef _ANALYSIS_H_
#define _ANALYSIS_H_

#include <string>
#include <vector>
#include "Student_info.h"

// Answer to Q6.6
double analysis(const std::vector<Student_info>&, double method(const Student_info&));
void write_analysis(std::ostream&,
	const std::string&,
	double method(const Student_info&),
	const std::vector<Student_info>&,
	const std::vector<Student_info>&);

#endif // !_ANALYSIS_H_
