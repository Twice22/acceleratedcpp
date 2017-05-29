// chapter5.3.cpp : définit le point d'entrée pour l'application console.
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

void test(bool verbose = false)
{

	Student_infos students;
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
	//sort(students.begin(), students.end(), compare); (for list we need list.sort()

	// CPU time
	clock_t start;
	start = clock();

	Student_infos fails = extract_fails(students);

	cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

	if (verbose) {
		// write the names and the grades of non failing students
		string msg_passed = "Names and Grades of students that passed: ";
		display(students, msg_passed, maxlen);

		// write the names and the grades students that fail
		string msg_failed = "\nNames and Grades of students that failed: ";
		display(fails, msg_failed, maxlen);
	}
}

int main() {
	cout << "test list or vect implementation (l/v): ";
	string choice;
	cin >> choice;

	if (choice == "l" || choice == "v") {
		test();
	}
	else {
		throw domain_error("You should enter either l or v!");
	}

	system("pause");
	return 0;
}


