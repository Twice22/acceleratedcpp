#include "stdafx.h"
#include "grade.h"
#include "median.h"
#include <numeric>
#include <algorithm>

using namespace std;

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final_grade, const std::vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("Student has done no homework!");
	return grade(midterm, final_grade, median(hw));
}

double grade(double midterm, double final_grade, double median) {
	return 0.2 * midterm + 0.4 * final_grade + 0.4 * median;
}

bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

double grade_aux(const Student_info& s) {
	try {
		return grade(s);
	}
	catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

double average(const vector<double>& v) {
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median(const Student_info& s) {
	// compute median only on homework that the students did (homework whose
	// grades are differents from 0)
	vector<double> nonzero;
	// only add non that are different from 0.0 to nonzero vector
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0.0);
	if (nonzero.empty()) {
		return grade(s.midterm, s.final, 0);
	}
	else {
		return grade(s.midterm, s.final, median(nonzero));
	}

}