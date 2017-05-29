// chapter8.2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "algo.h"

#include <string>
#include <iostream>

using namespace std;

bool passes(char c) {
	return c == 'P';
}

int main()
{
	// Answer to Q8.4
	string grades = "PPFFPFPFFFPPPF";
	my_partition(grades.begin(), grades.end(), passes);
	cout << grades << endl;

	system("pause");
    return 0;
}

