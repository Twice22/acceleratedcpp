// chapter13.6.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "Core.h"
#include "Grad.h"
#include "Student_info.h"
#include "grade.h" // Add Answer to Q13.6

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
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
		string type = students[i].type();
		cout << "(" << type << ") " << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}


	system("pause");
	return 0;
}

