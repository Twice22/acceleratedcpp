// chapter12.0.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "Str.h"

#include <iostream>

using namespace std;

int main()
{
	Str s("Hello, world !");

	// display Hello, world!
	for (Str::size_type i = 0; i < s.size(); i++) {
		cout << s[i];
	}
	cout << endl;

	s.clear();

	// should be 0
	cout << "size of string: " << s.size() << endl;

	system("pause");
    return 0;
}

