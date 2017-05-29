// chapter12.6.cpp : définit le point d'entrée pour l'application console.
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

