// chapter4.4.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int digits(double n, int nb_decimal)
{

	int result = nb_decimal + 1; // nb decimal + floating point

	if (n < 0) {
		result++; // add space for negative sign
	}

	while (n >= 1)
	{
		++result;
		n /= 10;
	}

	return result;
}

int digits(int n)
{

	int result = 0;

	if (n < 0) {
		result++; // add space for negative sign
	}

	while (n >= 1)
	{
		++result;
		n /= 10;
	}

	return result;
}

int main()
{
	cout << "Program that computes the square of the integers in range [a,b)\n"
		"lower bound a: ";
	double a;
	cin >> a;

	cout << "upper bound b: ";
	double b;
	cin >> b;

	double square = 0;

	int pad = 1;
	int accuracy = 2;

	int max_single = max(digits(a, accuracy), digits(b, accuracy));
	int max_square = max(digits(a * a, accuracy), digits(b * b, accuracy));

	int single_accuracy = max(digits(a), digits(b)) + accuracy;
	int square_accuracy = max(digits(a * a), digits(b * b)) + accuracy;

	for (double i = a; i < b; i += 1) {
		square = i * i;
		cout << setprecision(single_accuracy) << setw(max_single + pad) << i
			 << setprecision(square_accuracy) << setw(max_square + pad) << square << endl;
	}

	system("pause");
	return 0;
}



