// chapter12.12.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Str.h"
#include "Vec.h"

#include <iostream>

using namespace std;

int main()
{
	// Answer to Q12.9
	Str s = "Hello, World!";
	Str t = "--TROLLLL--";
	Str::iterator tb = t.begin(), te = t.end();

	Str::iterator pos = s.begin() + 3;
	s.insert(pos, tb, te);

	cout << s << endl;

	// Test Vec
	Vec<char> r(7, 'H');
	Vec<char> a(3, 'A');

	Vec<char>::iterator m = r.begin() + 3;
	r.insert(m, a.begin(), a.end());

	for (Vec<char>::const_iterator it = r.begin(); it != r.end(); ++it) {
		cout << *it;
	}
	cout << endl;


	system("pause");
	return 0;
}

