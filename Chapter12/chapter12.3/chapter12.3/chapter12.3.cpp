// chapter12.3.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Str.h"

#include <iostream>

using namespace std;

int main()
{

	// Test Q12.3
	Str s("Apple");
	Str s1("Orange");
	Str s2("Apple");

	cout << s << " == " << s1 << ": " << (s == s1) << endl;
	cout << s1 << " == " << s2 << ": " << (s1 == s2) << endl;
	cout << s << " == " << s2 << ": " << (s == s2) << endl;
	
	
	system("pause");
    return 0;
}

