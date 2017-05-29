#include "stdafx.h"
#include "analysis.h"
#include "grade.h"
#include "median.h"
#include <algorithm>
#include <numeric>

using namespace std;

// Answer to Q6.6
double analysis(const vector<Student_info>& s,
				double method(const Student_info&)) {
	vector<double> grades;
	transform(s.begin(), s.end(), back_inserter(grades), method);
	return median(grades);
}

void write_analysis(std::ostream& out,
	const std::string& name,
	double method(const Student_info&),
	const std::vector<Student_info>& did,
	const std::vector<Student_info>& didnt) {

	out << name << ": median(did) = " << analysis(did, method) <<
		", median(didnt) = " << analysis(didnt, method) << endl;
}