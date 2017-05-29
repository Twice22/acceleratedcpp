#include "stdafx.h"
#include "Core.h"
#include "grade.h"

using namespace std;

// Read only Core grade. As we will read thesis
// grade between final and homework grade and
// read_hw will read homework. read_common will only
// read midterm and final grades
istream& Core::read_common(istream& is) {
	is >> n >> midterm >> final;
	return is;
}

istream& Core::read(istream& is) {
	read_common(is);
	read_hw(is, homework);
	return is;
}

double Core::grade() const {
	// Answer to Q13.2
	cerr << "Core::grade()" << endl;
	return ::grade(midterm, final, homework);
}
