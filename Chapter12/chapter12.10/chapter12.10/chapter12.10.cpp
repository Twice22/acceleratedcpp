// chapter12.10.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Vec.h"
#include "Str.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// test Answer 12.10
	Vec<char> s(7, 'H');
	
	Str s_copy(s.begin(), s.end()-2);
	cout << s_copy << endl;

	system("pause");
    return 0;
}

