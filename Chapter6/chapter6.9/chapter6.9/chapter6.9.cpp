// chapter6.9.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string res;

void concat(const string& s) {
	res += s;
}

int main()
{
	// Answer to Q6.9
	vector<string> vec{"hello ! this is a test ", "the goal ", "is to concatenate ", "these strings"};
	
	for_each(vec.begin(), vec.end(), concat);

	// display
	cout << res << endl;

	system("pause");
    return 0;
}

