// chapter4.5.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "readstream.h"
#include "vectormanip.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "This program count the number of word in the input\n"
		"and how many time each word occurs\n" << endl;
	cout << "write several words separate by spaces: ";

	vector<string> wordlist = read_w(cin);

	vect_sz size = wordlist.size();

	cout << "You entered " << size << " numbers" << endl;
	display(wordlist);

	system("pause");
    return 0;
}

