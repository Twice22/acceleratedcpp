#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

istream& read_hw(istream& is, vector<double>& hw) {

	if (is) {
		// get rid of previous content
		hw.clear();

		double g;
		while (is >> g) {
			hw.push_back(g);
		}

		// clear the stream, so that input will work for next student;
		is.clear();
	}

	return is;
}