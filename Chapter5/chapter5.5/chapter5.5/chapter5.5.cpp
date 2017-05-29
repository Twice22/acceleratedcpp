// chapter5.5.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "framing.h"

using namespace std;

vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type string_size;
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
	/*string s;
	cout << "Enter a list of word separated by whitespace characters: ";
	while (getline(cin, s)) { // get a whole line until \EOF
	vector<string> v = split(s);

	// display each word in v
	for (vector<string>::size_type i = 0; i < v.size(); i++) {
	cout << v[i] << endl;
	}
	}*/
	vector<string> v{ "This is an", "example", "to", "illustrate", "framing" };
	vector<string> framed_v = center(v);

	// display center framing
	for (vector<string>::const_iterator it = framed_v.begin(); it != framed_v.end(); ++it) {
		cout << (*it) << endl;
	}

	system("pause");
	return 0;
}


