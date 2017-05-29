// chapter12.11.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "framing.h"

#include "Str.h"

using namespace std;

vector<Str> split(const Str& s) {
	vector<Str> ret;
	typedef Str::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		while (i != s.size() && isspace(s[i])) {
			i++;
		}
		string_size j = i;

		while (i != s.size() && isalpha(s[i])) {
			i++;
		}

		// we wide non-whitespace chars so we add it
		if (i != j) {
			ret.push_back(s.substr(j, i - j));
		}

	}
	return ret;
}

int main()
{
	Str s;
	cout << "Enter a list of word separated by whitespace characters: ";
	while (getline(cin, s)) { // get a whole line until \EOF
		vector<Str> v = split(s);

		// display each word in v
		for (vector<Str>::size_type i = 0; i < v.size(); i++) {
			cout << v[i] << endl;
		}
	}

	Str text[] = { "This is an", "example", "to", "illustrate", "framing" };
	vector<Str> v2;
	size_t size = sizeof(text) / sizeof(*text);
	for (size_t i = 0; i < size; ++i) {
		v2.push_back(text[i]);
	}

	vector<Str> framed_v = frame(v2);
	vector<Str> v_concat = vconcat(v2, framed_v);
	vector<Str> h_concat = hconcat(v2, framed_v);

	// display vertical framing
	for (vector<Str>::const_iterator it = v_concat.begin(); it != v_concat.end(); ++it) {
		cout << (*it) << endl;
	}

	// display horizontal framing
	for (vector<Str>::const_iterator it = h_concat.begin(); it != h_concat.end(); ++it) {
		cout << (*it) << endl;
	}

	system("pause");
	return 0;
}

