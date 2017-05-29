// chapter7.4.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "split.h"
#include "xreftable.h"

#include <iostream>

using namespace std;

int main()
{

	map<string, vector<int> > xrefmap = xref(cin);
	display_xref(xrefmap);

	system("pause");
	return 0;
}

