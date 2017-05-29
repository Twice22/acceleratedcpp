// chapter3.4.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cout << "Enter list of words (with or without repetition): ";

	vector<string> wlist;
	vector<double> wsize;
	string word;

	while (cin >> word) {
		wlist.push_back(word);
		wsize.push_back(word.size());
	}

	typedef vector<double>::size_type vect_size;
	typedef string::size_type str_size;
	vect_size size = wlist.size();

	if (size == 0) {
		cout << "You should pass some words!" << endl;
		system("pause");

		return 1;
	}

	sort(wsize.begin(), wsize.end());

	str_size min_len = wsize[0]; str_size max_len = wsize[size - 1];

	string minWord, maxWord;
	for (int i = 0; i < size; i++) {
		if (wlist[i].size() == min_len) {
			minWord = wlist[i];
		}
		if (wlist[i].size() == max_len) {
			maxWord = wlist[i];
		}
	}

	cout << "longest word: \"" << maxWord << "\"\n"
		"shortest word: \"" << minWord << "\"" << endl;

	system("pause");
	return 0;
}

