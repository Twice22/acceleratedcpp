// chapter5.10.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool palindrom(const string& s) {
	string::size_type sz = s.size(), i = 0;
	while (i < sz/2 && s[i] == s[sz - 1 - i]) {
		++i;
	}
	return (i == sz / 2);
}

void test() {
	cout << "Enter a word, I will tell if it's a palindrome or not: ";
	string word;
	cin >> word;

	if (palindrom(word)) {
		cout << "it's a palindrom!" << endl;
	}
	else {
		cout << "It's not a palindrom!" << endl;
	}
}

string longest_palindrom(const vector<string>& vec) {
	string longest;
	for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
		if (palindrom(*iter)) {
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

	// kinnikinnik longest palindrom!
	cout << longest_palindrom(vec) << endl;

	system("pause");
    return 0;
}

