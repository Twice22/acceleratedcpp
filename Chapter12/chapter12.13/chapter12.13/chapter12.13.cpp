// chapter12.13.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Vec.h"

#include <iostream>

using namespace std;

int main()
{
	Vec<char> v(20, 'H');

	const char* text = "Ni hao Shijie !";
	size_t len = strlen(text);

	v.assign(text, text + len);

	//display vec
	cout << v << endl;

	system("pause");
    return 0;
}

