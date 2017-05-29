// chapter11.6.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Vec.h"

#include <iostream>

using namespace std;

int main()
{
	Vec<double> v = Vec<double>(10, 5);

	v[5] = 0;

	// display
	for (Vec<double>::const_iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	Vec<double>::iterator iter = v.begin() + 5;
	v.erase(iter);

	// display after erasing
	for (Vec<double>::const_iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

