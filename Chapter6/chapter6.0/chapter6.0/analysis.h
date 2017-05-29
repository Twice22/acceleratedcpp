#pragma once
#ifndef _ANALYSIS_H_
#define _ANALYSIS_H_

#include <string>
#include <vector>
#include "Student_info.h"


double median_analysis(const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);

void write_analysis(std::ostream&,
	const std::string&,
	double analysis(const std::vector<Student_info>&),
	const std::vector<Student_info>&,
	const std::vector<Student_info>&);

#endif // !_ANALYSIS_H_
