// chapter7.8.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "findurl.h"
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

