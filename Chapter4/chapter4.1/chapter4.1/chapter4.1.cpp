// chapter4.1.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{

	vector<Student_info> students;
	Student_info record;

	// question 4.1
	// we need to pass 2 same arguments to the max function. So we need to
	// create a variable maxlen of the save type of record.name.size(), that
	// is to say string::size_type
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

	// write the names and the grades
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		// write the name, padded on the right to maxlen + 1 characters
		cout << students[i].name
			<< string(maxlen + 1 - students[i].name.size(), ' ');

		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	system("pause");
	return 0;
}