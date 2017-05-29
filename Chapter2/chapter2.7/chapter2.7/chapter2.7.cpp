// chapter2.7.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{

	for (int i = 10; i >= -5; i--) {
		cout << i << endl;
	}

	system("pause");
    return 0;
}

