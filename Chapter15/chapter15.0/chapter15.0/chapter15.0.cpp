// chapter15.0.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Ptr.h"
#include "Picture.h"

#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<string> v;
	v.push_back("Hello, World");
	v.push_back("How Are You Doing  ?");
	v.push_back("Gooood !");


	// Answer to Q15.1
	Picture p(v);
	Picture q = frame(p);
	Picture r = hcat(p, q);
	Picture s = vcat(q, r);

	Picture f = frame(hcat(s, vcat(r, q)));

	f.reframe('~', '@', '|');

	cout << f << endl;

	system("pause");
    return 0;
}

