// chapter12.7.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Str.h"

#include <iostream>

using namespace std;


int main()
{
	// Test Answer to Q12.7
	Str s("Hello, World");

	for (Str::const_iterator it = s.begin(); it != s.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

