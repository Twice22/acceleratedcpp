// chapter3.2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <ios>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cout << "Please enter several numbers: ";

	vector<double> list;
	double n;

	while (cin >> n) {
		list.push_back(n);
	}

	typedef vector<double>::size_type size_vec;
	size_vec size = list.size();

	if (size == 0) {
		cout << "Please enter at least one number!" << endl;
		return 1;
	}
	else if (size == 1) {
		cout << "All quarters are the same and are equal to : " << list[0] << endl;
		system("pause");
		return 0;
	}

	sort(list.begin(), list.end());

	// quarter and median (french way)
	size_vec mid = size / 2;
	double q2 = size % 2 == 0 ? (list[mid] + list[mid - 1]) / 2 : list[mid];

	double q1 = size % 2 == 1 ? list[(size - 1) / 4] : list[size / 4];
	double q3 = size % 2 == 1 ? list[1 + 3 * (size - 1) / 4] : list[3 * size / 4];


	cout << "The quarters are: \n"
		"Q1 : " << q1 <<
		"\nQ2 : " << q2 <<
		"\nQ3 : " << q3 << endl;

	system("pause");
    return 0;
}

