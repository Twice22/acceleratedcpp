// chapter3.5.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<string> students;
	vector<double> grades;

	cout << "student's name: ";
	string name;

	while (cin >> name) {
		students.push_back(name);

		double sum = 0, grade;
		int i = 0, nb_grade = 3;

		cout << "Enter the student's grades (3 grades): ";

		for (i; i < nb_grade; i++) {
			cin >> grade;
			sum += grade;
		}

		if (i == 0) {
			cout << "Error. You should pass at least one grade!";
			system("pause");

			return 1;
		}

		grades.push_back(sum / i);

		cout << "student's name: ";
	}

	// print student's name and grades
	typedef vector<string>::size_type vect_size;
	vect_size size = students.size();
	streamsize prev_prec = cout.precision(4);

	for (vect_size i = 0; i < size; i++) {
		cout << "student: " << students[i] << " has " << grades[i] << endl;
	}

	system("pause");
    return 0;
}

