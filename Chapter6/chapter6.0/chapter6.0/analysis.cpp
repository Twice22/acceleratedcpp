#include "stdafx.h"
#include "analysis.h"
#include "grade.h"
#include "median.h"
#include <algorithm>
#include <numeric>

using namespace std;

double median_analysis(const vector<Student_info>& s) {
	vector<double> grades;
	transform(s.begin(), s.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double average_analysis(const vector<Student_info>& s) {
	vector<double> grades;
	transform(s.begin(), s.end(), back_inserter(grades), average_grade);
	return median(grades);
}

// Answer to Q6.5
double optimistic_median_analysis(const vector<Student_info>& s) {
	vector<double> grades;
	transform(s.begin(), s.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

void write_analysis(std::ostream& out,
	const std::string& name,
	double analysis(const std::vector<Student_info>&),
	const std::vector<Student_info>& did,
	const std::vector<Student_info>& didnt) {

	out << name << ": median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}