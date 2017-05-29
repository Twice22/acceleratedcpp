#include "stdafx.h"
#include "framing.h"
#include <iostream>
#include <algorithm>

using namespace std;

Str::size_type maxwidth(const vector<Str>& s) {
	Str::size_type maxsize = 0;
	for (string_size i = 0; i != s.size(); i++) {
		maxsize = max(maxsize, s[i].size());
	}
	return maxsize;
}

vector<Str> frame(const vector<Str>& v) {
	vector<Str> ret;
	Str::size_type maxsize = maxwidth(v);
	Str border = Str(4 + maxsize, '*');

	ret.push_back(border);
	for (string_size i = 0; i != v.size(); i++) {
		ret.push_back("* " + v[i] + Str(maxsize - v[i].size(), ' ') + " *");
	}
	ret.push_back(border);

	return ret;
}

vector<Str> vconcat(const vector<Str>& top, const vector<Str>& bot) {
	// we can also use iterators
	vector<Str> ret = top;
	for (Str::size_type i = 0; i != bot.size(); i++) {
		ret.push_back(bot[i]);
	}
	return ret;

	// we can also write
	// ret.insert(red.end(), bottom.begin(), bottom.end());
}

vector<Str> hconcat(const vector<Str>& left, const vector<Str>& right) {

	vector<Str> ret;
	typedef vector<Str>::size_type vect_sz;
	vect_sz maxsize = max(left.size(), right.size());
	Str::size_type max_width = maxwidth(left) + 1;

	for (vect_sz i = 0; i < maxsize; i++) {
		Str str = "";
		if (i < left.size()) {
			str += left[i] + Str(max_width - left[i].size(), ' ');
		}
		else {
			str += Str(max_width, ' ');
		}

		if (i < right.size()) {
			str += right[i];
		}
		ret.push_back(str);
	}
	return ret;
}