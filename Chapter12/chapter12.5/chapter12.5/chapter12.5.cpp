// chapter12.5.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Str.h"

#include <iostream>

using namespace std;


int main()
{
	Str s("Hello, ");
	Str s1("World!");

	// test operator+(const Str&, const Str&);
	cout << s + s1 << endl;

	// test operator+(const Str&, consr char*)
	char* name = "Victor ";
	cout << s + name << endl;

	// test operator+(const char*, const Str&)
	cout << name + s1 << endl;


	system("pause");
    return 0;
}

