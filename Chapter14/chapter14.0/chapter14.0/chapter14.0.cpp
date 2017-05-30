// chapter14.0.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Core.h"
#include "Grad.h"
#include "Student_info.h"
#include "Ptr.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// Answer to Q14.1
bool compare_Core_handles(const Ptr<Core>& lhs, const Ptr<Core>& rhs) {
	return compare(*lhs, *rhs);
}

// Answer to Q14.3
int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store the data
	char ch;
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size()); // `Ptr<T>::->'
		students.push_back(record);
	}

	// sort by name
	sort(students.begin(), students.end(), Student_info::compare); // change fct

	// write the names and grades
	for (vector<Student_info>::size_type i = 0;
		i != students.size(); ++i) {
		cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
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

