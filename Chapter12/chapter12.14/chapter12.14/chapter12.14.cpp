// chapter12.14.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "Vec.h"

#include <iostream>

using namespace std;

int main()
{
	// test Answer Q12.14
	string s = "Ni hao Shijie !";
	Vec<char> v(s);

	//display vec
	cout << v << endl;

	system("pause");
	return 0;
}

