// chapter12.6.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "Str.h"

#include <iostream>

using namespace std;

int main()
{
	Str s;
	//Str s("Hello");
	if (s) {
		cout << "s is defined!";
	}
	else {
		cout << "s is undefined!";
	}
	cout << endl;

	system("pause");
    return 0;
}

