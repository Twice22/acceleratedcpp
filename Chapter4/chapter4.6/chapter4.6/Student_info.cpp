#include "stdafx.h"
#include "Student_info.h"
#include "grade.h"

using namespace std;

bool compare(const Student_info& s1, const Student_info& s2) {
	return s1.name < s2.name;
}

istream& read(istream& in, Student_info& s) {
	double midterm, final_exam;
	vector<double> hw;

	in >> s.name >> midterm >> final_exam;
	read_hw(in, hw);

	try {
		s.total_grade = grade(midterm, final_exam, hw);
	}
	catch (domain_error e) {
		e.what();
	}
	
	return in;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in)
	{
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}