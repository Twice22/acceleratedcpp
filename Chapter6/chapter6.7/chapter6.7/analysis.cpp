#include "stdafx.h"
#include "analysis.h"
#include "grade.h"
#include "median.h"
#include <algorithm>
#include <numeric>

using namespace std;

// Answer to Q6.6
double analysis(const Student_infos& s,
	double method(const Student_info&)) {
	vector<double> grades;
	transform(s.begin(), s.end(), back_inserter(grades), method);
	return median(grades);
}

void write_analysis(std::ostream& out,
	const std::string& name,
	double method(const Student_info&),
	const Student_infos& did,
	const Student_infos& didnt) {

	out << name << ": median(did) = " << analysis(did, method) <<
		", median(didnt) = " << analysis(didnt, method) << endl;
}