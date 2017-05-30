#include "stdafx.h"
#include "grade.h"

using namespace std;

double grade(double midterm, double final, const vector<double>& homework) {
	if (homework.size() == 0) throw domain_error("student has done no homework");
	return grade(midterm, final, median(homework));
}

double grade(double midterm, double final, double hw) {
	return 0.2 * midterm + 0.4 * final + 0.4 * hw;
}