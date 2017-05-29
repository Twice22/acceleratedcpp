// chapter5.8.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "framing.h"

using namespace std;


int main()
{
	vector<string> v{ "This is an", "example", "to", "illustrate", "framing" };
	vector<string> framed_v = frame(v);
	vector<string> h_concat = hconcat(v, framed_v);

	// display horizontal framing
	for (vector<string>::const_iterator it = h_concat.begin(); it != h_concat.end(); ++it) {
		cout << (*it) << endl;
	}

	system("pause");
	return 0;
}


