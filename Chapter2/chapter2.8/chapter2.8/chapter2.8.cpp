// chapter2.8.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int r = 1;
	for (int i = 1; i < 10; i++) {
		r *= i;
	}

	cout << r << endl;

	system("pause");
    return 0;
}

