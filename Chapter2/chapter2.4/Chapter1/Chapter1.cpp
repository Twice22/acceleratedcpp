// Chapter1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	cout << "Please enter your first name: ";
	string name;
	cin >> name;

	const string greeting = "Hello " + name + "!";

	cout << "Enter number of padding: ";
	int pad;
	cin >> pad;
	const int rows = 3 + 2 * pad; // 3 rows for ***, hello and *** + 2 * size of padding
	const string::size_type cols = greeting.size() + 2 * pad + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		while (c != cols) {
			if (r == pad + 1 && c == 1 + pad) {
				cout << greeting;
				c += greeting.size();
			}
			else {
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) { // if frame
					cout << "*";
					++c;
				}
				else {
					if (r != pad + 1) {
						cout << string(cols - 2, ' ');
						c += cols - 2;
					}
					else {
						cout << string(pad, ' ');
						c += pad;
					}					
				}
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

