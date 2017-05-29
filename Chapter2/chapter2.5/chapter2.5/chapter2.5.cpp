// chapter2.5.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;


int main()
{
	cout << "Enter length of rectangle: ";
	int length;
	cin >> length;

	cout << "Enter height of rectangle: ";
	int height;
	cin >> height;

	// draw rectangle
	for (int i = 0; i < height; i++) {
		cout << string(length, '*') + "\n";
	}

	cout << endl;

	// draw square
	for (int i = 0; i < height; i++) {
		cout << string(height, '*') + "\n";
	}

	cout << endl;

	// draw triangle
	for (string::size_type i = 0; i < length; i++) {
		string spaces = string((length - i) / 2, ' ');
		cout << spaces + string(i, '*') + "\n";
	}

	system("pause");
    return 0;
}

