// chapter3.6.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <ios>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;			using std::sort;
using std::cout;		using std::endl;
using std::streamsize;	using std::string;
using std::vector;		using std::setprecision;

int main()
{
	cout << "Please enter your first name: ";
	string name;
	cin >> name;

	cout << "Hello " << name << "!" << endl;

	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final grades: ";
	double midterm, final_grade;
	cin >> midterm >> final_grade;

	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	double sum = 0, n = 0;
	int count = 0;

	// add all the grades in homework vector
	// NOTE: will only work on Linux. In order to work on windows the user may enter Ctrl+Z
	// see: http://stackoverflow.com/questions/10371807/why-while-stdcin-foo-syntax-does-not-work
	while (cin >> n) {
		++count;
		sum += n;
	}

	// size is an unsigned int so no need to test if < 0
	if (count == 0) {
		cout << "Error. Please provide at least one grade." << endl;

		system("pause");
		return 1;
	}

	// save previous precision
	streamsize previous_prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final_grade + 0.4 * sum / count
		<< setprecision(previous_prec) << endl;


	system("pause");
	return 0;
}

