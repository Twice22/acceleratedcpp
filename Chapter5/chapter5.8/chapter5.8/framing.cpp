#include "stdafx.h"
#include "framing.h"
#include <iostream>
#include <algorithm>

using namespace std;

string_size maxwidth(const vector<string>& s) {
	string_size maxsize = 0;
	for (string_size i = 0; i != s.size(); i++) {
		maxsize = max(maxsize, s[i].size());
	}
	return maxsize;
}

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string_size maxsize = maxwidth(v);
	string border = string(4 + maxsize, '*');

	ret.push_back(border);
	for (string_size i = 0; i != v.size(); i++) {
		ret.push_back("* " + v[i] + string(maxsize - v[i].size(), ' ') + " *");
	}
	ret.push_back(border);

	return ret;
}

// Answer to Q5.8
vector<string> hconcat(const vector<string>& left, const vector<string>& right) {

	vector<string> ret;
	string_size max_width = maxwidth(left) + 1;
	vector<string>::size_type i = 0, j = 0;

	// we define string s outside of the while loop
	// that will cause an issue
	string s;

	while (i < left.size() || j < right.size()) {
		

		if (i < left.size()) {
			s = left[i++];
		}

		// problem here! If there no more string in the left vector
		// then s won't be reset (string s outside the while loop)
		// at the next iteration, causing s.size() to be higher than
		// max_width and so resulting in max_width - s.size() < 0...
		// but string accept and unsigned int and so will be cast to
		// an unsigned int of around 4 billion... memory crashes
		s += string(max_width - s.size(), ' ');

		if (j < left.size()) {
			s += right[j++];
		}
		ret.push_back(s);
	}

	return ret;

}