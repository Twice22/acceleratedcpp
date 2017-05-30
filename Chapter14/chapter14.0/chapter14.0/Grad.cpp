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
	return min(Core::grade(), thesis);
}