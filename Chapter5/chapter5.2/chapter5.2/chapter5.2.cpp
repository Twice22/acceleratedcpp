// chapter5.0.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime>

#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"

using namespace std;

void main_v(bool verbose = false)
{

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all the students' data
	// students contains all the student records read so far
	// maxlen contains the length of the longest name in students
	while (read(cin, record)) {
		// find length of longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// CPU time
	clock_t start;
	start = clock();

	vector<Student_info> fails = extract_fails(students);

	cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

	if (verbose) {
		// write the names and the grades of non failing students
		string msg_passed = "Names and Grades of students that passed: ";
		display_v(students, msg_passed, maxlen);

		// write the names and the grades students that fail
		string msg_failed = "\nNames and Grades of students that failed: ";
		display_v(fails, msg_failed, maxlen);
	}
}

void main_l(bool verbose=false)
{

	list<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all the students' data
	// students contains all the student records read so far
	// maxlen contains the length of the longest name in students
	while (read(cin, record)) {
		// find length of longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// alphabetize the student records
	students.sort(compare);

	// CPU time
	clock_t start;
	start = clock();

	list<Student_info> fails = extract_fails(students);

	cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

	
	if (verbose) {
		// write the names and the grades of non failing students
		string msg_passed = "Names and Grades of students that passed: ";
		display_l(students, msg_passed, maxlen);

		// write the names and the grades students that fail
		string msg_failed = "\nNames and Grades of students that failed: ";
		display_l(fails, msg_failed, maxlen);
	}

}

int main() {
	cout << "test list or vect implementation (l/v): ";
	string choice;
	cin >> choice;

	if (choice == "l") {
		main_l();
	}
	else if (choice == "v") {
		main_v();
	}
	else {
		throw domain_error("You should enter either l or v!");
	}

	system("pause");
	return 0;
}
