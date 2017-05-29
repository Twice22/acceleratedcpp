#include "stdafx.h"
#include "Student_info.h"
#include "grade.h"

using namespace std;

istream& read(istream& in, Student_info& s) {
	double midterm, final_exam;
	vector<double> hw;

	in >> s.name >> midterm >> final_exam;
	read_hw(in, hw);

	try {
		s.total = grade(midterm, final_exam, hw);
	}
	catch (domain_error e) {
		s.total = grade(midterm, final_exam, 0);
	}
	

	return in;
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		double n;

		// get rid of previous content
		hw.clear();

		// read homework grades
		while (in >> n) {
			hw.push_back(n);
		}

		// clear the stream so that the ouput will work for the next student
		in.clear();
	}
	return in;
}