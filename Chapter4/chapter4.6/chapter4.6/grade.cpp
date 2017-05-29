#include "stdafx.h"
#include "grade.h"
#include "median.h"

using namespace std;


double grade(double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(double midterm, double final_exam, double hw) {
	return 0.2 * midterm + 0.4 *  final_exam +0.4 * hw;
}