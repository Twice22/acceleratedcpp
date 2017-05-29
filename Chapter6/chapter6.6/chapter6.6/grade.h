#pragma once
#ifndef GRADE_GUARD
#define GRADE_GUARD

#include <vector>
#include "Student_info.h"

double grade(const Student_info&);
double grade(double, double, const std::vector<double>&);
double grade(double, double, double);
bool fgrade(const Student_info&);

double grade_aux(const Student_info&);
double average(const std::vector<double>&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info&);

#endif