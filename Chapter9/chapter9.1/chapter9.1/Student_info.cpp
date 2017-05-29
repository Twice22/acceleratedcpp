#include "stdafx.h"
#include "Student_info.h"
#include "grade.h"

using namespace std;

bool compare(const Student_info& s1, const Student_info& s2) {
	return s1.name() < s2.name();
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

// Constructor with a sequence of constructor initializers
Student_info::Student_info() : total_grade(0) {}

// Constructor that read from input stream
Student_info::Student_info(istream& in) { read(in); };

// Answer to Q9.1
istream& Student_info::read(istream& in) {
	double mid, fin;
	in >> n >> midterm >> final;
	read_hw(in, homework);
	total_grade = ::grade(midterm, final, homework);
	return in;
}

// Answer to Q9.1
double Student_info::grade() const {
	return total_grade;
}