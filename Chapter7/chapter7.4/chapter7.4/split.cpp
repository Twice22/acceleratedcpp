#include "stdafx.h"
#include "split.h"
#include <algorithm>

using namespace std;

bool space(char c) {
	return isspace(c);
}

bool notspace(char c) {
	return !isspace(c);
}

vector<string> split(const string& s) {

	vector<string> ret;
	typedef string::const_iterator s_it;

	s_it b = s.begin(), e = s.end();

	while (b != e) {
		b = find_if(b, e, notspace);

		// need a l_value (so !is_space won't work !)
		s_it after = find_if(b, e, space);

		if (b != e) {
			ret.push_back(string(b, after));
		}
		b = after;
	}
	return ret;
}