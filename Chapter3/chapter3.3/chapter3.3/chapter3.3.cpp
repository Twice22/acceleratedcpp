// chapter3.3.cpp : définit le point d'entrée pour l'application console.
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
	string word;

	while (cin >> word) {
		wlist.push_back(word);
	}

	typedef vector<double>::size_type vect_size;
	vect_size size = wlist.size();

	if (size == 0) {
		cout << "You should pass some words!" << endl;
		system("pause");

		return 1;
	}

	sort(wlist.begin(), wlist.end());

	vect_size count;
	for (int i = 0; i < size; i += count) {
		vect_size j = i + 1;
		count = 1;
		while (j < size && wlist[j] == wlist[i]) {
			count++; j++;
		}
		cout << "word \"" << wlist[i] << "\" appears " << count << " time(s)" << endl;
	}

	system("pause");
    return 0;
}

