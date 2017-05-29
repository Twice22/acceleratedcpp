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

vector<string> vconcat(const vector<string>& top, const vector<string>& bot) {
	// we can also use iterators
	vector<string> ret = top;
	for (string_size i = 0; i != bot.size(); i++) {
		ret.push_back(bot[i]);
	}
	return ret;

	// we can also write
	// ret.insert(red.end(), bottom.begin(), bottom.end());
}

vector<string> hconcat(const vector<string>& left, const vector<string>& right) {

	vector<string> ret;
	typedef vector<string>::size_type vect_sz;
	vect_sz maxsize = max(left.size(), right.size());
	string_size max_width = maxwidth(left) + 1;

	for (vect_sz i = 0; i < maxsize; i++) {
		string str = "";
		if (i < left.size()) {
			str += left[i] + string(max_width - left[i].size(), ' ');
		}
		else {
			str += string(max_width, ' ');
		}

		if (i < right.size()) {
			str += right[i];
		}
		ret.push_back(str);
	}
	return ret;
}