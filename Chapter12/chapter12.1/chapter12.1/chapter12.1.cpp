// chapter12.1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Str.h"

#include <iostream>

using namespace std;

int main()
{
	Str s("Hello, World!");

	for (Str::size_type i = 0; i < s.size(); ++i) {
		cout << s[i];
	}
	cout << endl;

	s[6] = 'M';

	for (Str::size_type i = 0; i < s.size(); ++i) {
		cout << s[i];
	}
	cout << endl;

	cout << Str() << endl;
	cout << Str(7, 'Z') << endl;

	Str s4 = "Hello";
	cout << s4 << endl;
	Str::iterator s1 = s4.begin();
	Str::iterator s2 = s4.end();

	Str test(s1, s2);
	cout << test << endl;

	system("pause");
    return 0;
}

