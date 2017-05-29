#include "stdafx.h"
#include "Student_info.h"
#include "classify.h"
#include <algorithm>

using namespace std;

// criteria
bool pgrade(const Student_info& s) {
	return !fgrade(s);
}

// Answer to Q6.8 (function not used)
Student_infos classify(Student_infos& students, bool criteria(const Student_info&)) {
	// rearrange the elements in students. elements that satisfy the predicate criteria
	// precede the ones that don't satisfy pgrade. It returns an iterator that represents the second
	// element of the second section
	Student_infos::iterator iter = stable_partition(students.begin(), students.end(), criteria);

	// fail is construct as a copy of student from range iter to the end
	Student_infos fail(iter, students.end());

	// erase failing students from students
	students.erase(iter, students.end());

	return fail;
}

void display(const Student_infos& vec, string s, string::size_type maxlen) {
	cout << s << endl;
	for (Student_infos::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		// write the name, padded on the right to maxlen + 1 characters
		cout << it->name
			<< string(maxlen + 1 - it->name.size(), ' ');

		try {
			double final_grade = grade(*it);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
}