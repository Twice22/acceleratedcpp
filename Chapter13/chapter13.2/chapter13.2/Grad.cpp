#include "stdafx.h"
#include "Grad.h"

#include <algorithm>

using namespace std;

istream& Grad::read(istream& is) {
	Core::read_common(is);
	is >> thesis;
	read_hw(is, homework);
	return is;
}

// obtain grade as being the min between thesis
// and global grade obtained from other assignments
double Grad::grade() const {
	// need to use Core:: otherwise we would have call
	// Grad::grade and so... recursive call
	// Answer to Q13.2
	cerr << "Grad::grade()" << endl;
	return min(Core::grade(), thesis);
}

bool compare_grades(const Core& c1, const Core& c2) {
	return c1.grade() < c2.grade();
}