// chapter9.5.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all the students' data
	// students contains all the student records read so far
	// maxlen contains the length of the longest name in students
	while (record.read(cin)) {
		// find length of longest name
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records (Asked by Q9.5)
	sort(students.begin(), students.end(), compare);

	// write the names and the grades
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

		// write the name, padded on the right to maxlen + 1 characters
		cout << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ');

		try {
			// pass or fail
			string p_or_f = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << p_or_f << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

