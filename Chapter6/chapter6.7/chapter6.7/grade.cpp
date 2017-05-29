#include "stdafx.h"
#include "grade.h"
#include "median.h"
#include <numeric>
#include <algorithm>

using namespace std;

double grade(double midterm, double final_grade, const std::vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("Student has done no homework!");
	return grade(midterm, final_grade, ::median(hw));
}

double grade(double midterm, double final_grade, double median) {
	return 0.2 * midterm + 0.4 * final_grade + 0.4 * median;
}

double average(const vector<double>& v) {
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}