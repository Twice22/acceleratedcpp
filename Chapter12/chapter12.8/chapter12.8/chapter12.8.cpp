// chapter12.8.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Str.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("test.txt", ifstream::in);
	Str s;
	while (getline(in, s)) {
		cout << s << endl;
		cout << "-- newline --" << endl;
	}

	system("pause");
	return 0;
}

