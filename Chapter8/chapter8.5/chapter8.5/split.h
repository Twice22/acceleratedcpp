#pragma once
#ifndef _SPLIT_
#define _SPLIT_

#include <vector>
#include <string>

bool space(char);
bool notspace(char);

template <class Out>
void split(const string& s, Out os) {

	vector<string> ret;
	typedef string::const_iterator s_it;

	s_it b = s.begin(), e = s.end();

	while (b != e) {
		b = find_if(b, e, notspace);

		// need a l_value (so !is_space won't work !)
		s_it after = find_if(b, e, space);

		if (b != e) {
			*os++ = string(b, after);
		}
		b = after;
	}
	return ret;
}

#endif