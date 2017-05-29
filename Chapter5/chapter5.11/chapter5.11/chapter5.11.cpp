// chapter5.11.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool asc_desc(const string& s) {
	string::size_type sz = s.size(), i = 0;
	while (i < sz) {
		if (s[i] == 'b' || s[i] == 'd' || s[i] == 'f' ||
			s[i] == 'h' || s[i] == 'k' || s[i] == 'l' ||
			s[i] == 'g' || s[i] == 'j' || s[i] == 'p' ||
			s[i] == 'q' || s[i] == 'y') {
			return true;
		}
		i++;
	}
	return false;
}

void test() {
	cout << "Enter a word, I will tell if it's contain ascender/descender";
	string word;
	cin >> word;

	if (asc_desc(word)) {
		cout << "it contains ascender/descender" << endl;
	}
	else {
		cout << "It doesn't contain ascender/descender" << endl;
	}
}

string longest_nonascdesc(const vector<string>& vec) {
	string longest;
	for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
		if (!asc_desc(*iter)) {
			longest = (*iter).size() > longest.size() ? *iter : longest;
		}
	}
	return longest;
}

int main()
{
	// test if a word is a palindrom
	//test();

	cout << "Copy/Paste list of english word:" << endl;
	vector<string> vec;
	string word;
	while (cin >> word) {
		vec.push_back(word);
	}

	// it depends on the wordlist passed to the program
	// counterexcommunication longest word without ascender/descender
	cout << longest_nonascdesc(vec) << endl;

	system("pause");
	return 0;
}



