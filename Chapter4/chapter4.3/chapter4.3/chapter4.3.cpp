// chapter4.3.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	cout << "Program that computes the square of the integers in range [a,b)\n"
		"lower bound a: ";
	
	int a;
	cin >> a;

	cout << "upper bound b: ";
	int b;
	cin >> b;

	int square = 0;
	int max_single = max(to_string(a).size(), to_string(b).size()) + 1; // add 1 for padding
	int max_square = max(to_string(a * a).size(), to_string(b * b).size()) + 1; // add 1 for padding

	for (int i = a; i < b; i++) {
		square = i * i;
		cout << setw(max_single) << i << setw(max_square) << square << endl;
	}

	system("pause");
	return 0;
}

