#include "stdafx.h"
#include "Student_info.h"

using namespace std;

bool compare(const Student_info& s1, const Student_info& s2) {
	return s1.name < s2.name;
}

istream& read(istream& in, Student_info& s) {
	in >> s.name >> s.midterm >> s.final;
	read_hw(in, s.homework);
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