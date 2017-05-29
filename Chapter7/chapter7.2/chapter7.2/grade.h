#pragma once
#ifndef GRADE_GUARD
#define GRADE_GUARD

#include <vector>
#include <string>
#include "Student_info.h"

std::string gradetoletter(double);
std::string grade(double, double, const std::vector<double>&);
std::string grade(double, double, double);

#endif