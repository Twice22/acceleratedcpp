// chapter5.9.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool containUppercase(const string& s) {
	typedef vector<string>::size_type vect_sz;
	vect_sz sz = s.size();
	for (vect_sz i = 0; i < sz; i++) {
		if (isupper(s[i])) {
			return true;
		}
	}
	return false;
}

bool compare(string s1, string s2) {
	if (containUppercase(s2) && !containUppercase(s1)) {
		return true;
	}
	return false;
}

void sortUppercase(vector<string>& vec) {
	sort(vec.begin(), vec.end(), compare);
}

int main()
{
	cout << "Write words separated by spaces: ";
	vector<string> wordvec;
	string word;
	while (cin >> word) {
		wordvec.push_back(word);
	}

	sortUppercase(wordvec);

	// display
	for (vector<string>::size_type i = 0; i < wordvec.size(); i++) {
		cout << wordvec[i] << " ";
	}

	system("pause");
    return 0;
}

