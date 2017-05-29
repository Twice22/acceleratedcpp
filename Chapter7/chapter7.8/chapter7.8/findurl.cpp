#include "stdafx.h"
#include "findurl.h"
#include <algorithm>

using namespace std;


bool not_url_char(char c) {
	static const string s = "~;/?:@=&$-_.+!*'(),";
	return !(isalnum(c) || find(s.begin(), s.end(), c) != s.end());
}

string::const_iterator end_urls(string::const_iterator b, string::const_iterator e) {
	return find_if(b, e, not_url_char);
}

string::const_iterator begin_urls(string::const_iterator b, string::const_iterator e) {
	static const string sep = "://";
	typedef string::const_iterator iter;
	iter m = b;

	while ((m = search(m, e, sep.begin(), sep.end())) != e) {
		// the string shouln't begin or end by "://"
		if (m != b && m + sep.size() != e) {

			// find beginning
			iter beg = m;
			while (beg != b && isalpha(beg[-1]))
				beg--;

			// if one appropriate char before and after sep
			if (beg != m && !not_url_char(m[sep.size()]))
				return beg;
		}
		m += sep.size();
	}
	return e;
}

vector<string> find_urls(const string& s) {
	vector<string> ret;
	
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	while (b != e) {
		b = begin_urls(b, e);

		// if we find the beginning of an url
		if (b != e) {
			iter after = end_urls(b, e);
			ret.push_back(string(b, after));
			b = after;
		}
	}
	return ret;
}