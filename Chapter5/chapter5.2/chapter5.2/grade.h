#pragma once
#ifndef GRADE_GUARD
#define GRADE_GUARD

#include <vector>
#include "Student_info.h"

double grade(const Student_info&);
double grade(double, double, const std::vector<double>&);
double grade(double, double, double);
bool fgrade(const Student_info&);

#endif