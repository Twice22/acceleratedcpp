// chapter6.1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string::size_type maxwidth(const vector<string>& vec) {
	typedef vector<string>::const_iterator iter;
	iter it = vec.begin();
	string::size_type maxsize = 0;

	while (it != vec.end()) {
		if (it->size() > maxsize)
			maxsize = it->size();
		it++;
	}
	return maxsize;
}

vector<string> frame(const vector<string>& vec) {
	typedef vector<string>::const_iterator iter;
	vector<string> ret;

	string::size_type maxsize = maxwidth(vec);
	iter it = vec.begin();

	string border(maxsize + 4, '*');
	ret.push_back(border);
	for (; it != vec.end(); it++) {
		ret.push_back("* " + (*it) + string(maxsize - it->size(), ' ') + " *");
	}
	ret.push_back(border);

	return ret;

}

vector<string> hcat(const vector<string>& vecl, const vector<string>& vecr) {
	typedef vector<string>::const_iterator iter;
	vector<string> ret;

	string::size_type maxsize = maxwidth(vecl) + 1;
	iter i = vecl.begin(), j = vecr.begin();

	while (i != vecl.end() || j != vecr.end()) {
		string s;

		if (i != vecl.end()) {
			s = *(i++);
		}

		// need s.size() here and not i->size() as
		// `i` could have reach the end and then i->size() doesn't make sense.
		s += string(maxsize - s.size(), ' ');

		if (j != vecr.end()) {
			s += *(j++);
		}
		ret.push_back(s);
	}
	return ret;
}

int main()
{
	vector<string> u{ "Hello and", "welcome", "I'm happy", "to show you", "my code" };
	vector<string> v = frame(u);

	vector<string> w = hcat(u, v);

	// display
	for (vector<string>::const_iterator iter = w.begin(); iter != w.end(); iter++) {
		cout << *iter << endl;
	}

	system("pause");
    return 0;
}

