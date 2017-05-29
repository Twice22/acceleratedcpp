// chapter4.2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	cout << "Program that computes the square of the first 100 integers\n"
		"Press a button to execute..." << endl;
	system("pause");

	int square = 0;
	for (int i = 0; i <= 100; i++) {
		square = i * i;
		cout << setw(3) << i << setw(6) << square << endl;
	}

	system("pause");
    return 0;
}

