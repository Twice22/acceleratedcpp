// chapter12.9.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "Str.h"

#include <iostream>

using namespace std;

int main()
{
	// Answer to Q12.9
	Str s = "Hello, World!";
	ostream_iterator<char> os(cout, "");
	os << s << "\n";


	system("pause");
    return 0;
}

