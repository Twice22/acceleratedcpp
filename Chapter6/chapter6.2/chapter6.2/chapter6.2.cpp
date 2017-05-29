// chapter6.2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include "algorithms.h"

using namespace std;


int main()
{
	string s, text;
	cout << "Enter a text with urls:" << endl;

	// use a while and not a for otherwise compiler expect an `;`!
	while (getline(cin, text)) {
		s += text;
	}
	vector<string> urls = find_urls(s);

	// display
	for (vector<string>::const_iterator it = urls.begin(); it != urls.end(); ++it) {
		cout << (*it) << endl;
	}

	system("pause");
    return 0;
}

