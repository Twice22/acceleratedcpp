// chapter12.2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Str.h"

#include <iostream>

using namespace std;

int main()
{
	Str s("Hello, World!");

	// test data
	cout << s.data() << endl;

	// test c_str
	cout << s.c_str() << endl;

	// test copy
	char buffer[20];
	Str::size_type str_len = s.copy(buffer, 6, 6);
	buffer[str_len] = 0; // null-terminated the string
	cout << buffer << endl;


	system("pause");
	return 0;
}

