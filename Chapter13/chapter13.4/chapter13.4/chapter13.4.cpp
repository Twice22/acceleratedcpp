// chapter13.4.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Core.h"
#include "Grad.h"
#include "Student_info.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	/*
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store the data
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// sort by name
	sort(students.begin(), students.end(), Student_info::compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0;
		i != students.size(); ++i) {
		cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			// Answer to Q13.4
			cout << setprecision(3) << letter_grade(final_grade) << setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	*/

	// Test Q13.5
	Student_info s(cin);

	if (s.is_all_hw_done()) {
		cout << "All homework is done!" << endl;
	}
	else {
		cout << "You missed an assignment bitch!" << endl;
	}

	system("pause");
	return 0;
}

