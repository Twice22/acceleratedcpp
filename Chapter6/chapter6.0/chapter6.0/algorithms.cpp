#include "stdafx.h"
#include "algorithms.h"

using namespace std;

// true if the argument is whitespace, false otherwise
bool space(char c) {
	return isspace(c);
}

// false if the argument is whitespace, true othewise
bool not_space(char c) {
	return !isspace(c);
}

// algorithm that use <algorithm> to split a string
vector<string> split(const string& s) {
	typedef string::const_iterator iter;
	vector<string> ret;

	iter it = s.begin();

	while (it != s.end()) {
		it = find_if(it, s.end(), not_space);

		iter it2 = find_if(it, s.end(), space);

		if (it != s.end()) {
			ret.push_back(string(it, it2));
		}
		it = it2;

	}

	return ret;
}

// true if the argument is a palindrom, false otherwise (using <algorithm>)
bool is_palindrom(const string& s) {
	return equal(s.begin(), s.end(), s.rbegin());
}

bool not_url_char(char c) {
	static const string url_ch = "~;?/:@=&$-_.+!*'(),";

	// return false if char not in alpha or url_ch
	return !(isalpha(c) || 
		     find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator end_url(string::const_iterator b, string::const_iterator e) {
	return find_if(b, e, not_url_char);
}

string::const_iterator begin_url(string::const_iterator b, string::const_iterator e) {
	static const string sep = "://";

	typedef string::const_iterator iter;
	iter b1 = sep.begin(), e1 = sep.end(), i = b;

	while ((i = search(b, e, b1, e1)) != e) {
		
		// the separator "://" shouldn't be at the beginning or at the end of the string
		// otherwise it doesn't separate a protocol-name from a ressource-name
		if (i != b && i + sep.size() != e) {

			// find the beginning of the protocol name
			iter beg = i;
			while (beg != b && isalpha(beg[-1])) {
				beg--;
			}

			// if there is one character before the sep and one after, then we supposed
			// it is a correct url:
			if (beg != i && !not_url_char(i[sep.size()]) ) {
				return beg;
			}
		}
		i += sep.size();
	}
	return e;

}

// return each url found in its input
vector<string> find_urls(const string& s) {
	vector<string> ret;
	typedef string::const_iterator iter;

	iter it = s.begin(), end = s.end();

	while (it != end) {
		it = begin_url(it, end);

		// if we found a url
		if (it != end) {
			iter after = end_url(it, end);
			ret.push_back(string(it, after));
			it = after;
		}
	}
	return ret;
}
