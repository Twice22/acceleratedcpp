// chapter12.9.cpp : définit le point d'entrée pour l'application console.
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

