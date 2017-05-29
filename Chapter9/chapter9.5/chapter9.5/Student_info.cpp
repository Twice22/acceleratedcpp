#include "stdafx.h"
#include "Student_info.h"
#include "grade.h"

using namespace std;

bool compare(const Student_info& s1, const Student_info& s2) {
	return s1.name() < s2.name();
}

// Constructor with a sequence of constructor initializers
Student_info::Student_info() : midterm(0), final(0) {}

// Constructor that read from input stream
Student_info::Student_info(istream& in) { read(in); };

istream& Student_info::read(istream& in) {
	in >> n >> midterm >> final;
	g = ::grade(midterm, final);
	return in;
}

string Student_info::grade() const {
	return ::grade(midterm, final);
}