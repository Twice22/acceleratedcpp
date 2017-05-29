// project2.9.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{

	cout << "First integer: ";
	int a;
	cin >> a;

	cout << "Second integer: ";
	int b;
	cin >> b;

	if (a > b) {
		cout << a << " is greater than " << b << endl;
	}
	else if (a < b) {
		cout << a << " is lower than " << b << endl;
	}
	else {
		cout << a << " is equal to " << b << endl;
	}

	system("pause");
    return 0;
}

