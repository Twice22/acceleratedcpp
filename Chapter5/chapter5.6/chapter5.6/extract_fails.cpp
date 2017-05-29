#include "stdafx.h"
#include "extract_fails.h"

using namespace std;

// Answer to Q5.6
/*
Obviously this function is slower than the one implemented in 5.0 or 5.3 because, while
we were only adding elements to a vector/list and erasing elements (2 operations), here we
are adding elements to a vector/list, inserting elements back to the beginning of the vector (costly)/list
and then resizing the vector (3 operations). Moreover if we are using vector, inserting
an element at the beginning of the vector will have for side effect to shift all the elements of
the vector by one (so even worse if we are dealing with vector).
*/
Student_infos extract_fails(Student_infos& students) {

	Student_infos fails;
	Student_infos::iterator iter = students.begin();
	Student_infos::size_type orig_size = students.size();

	while (iter != students.end()) {
		if (!fgrade(*iter)) { // failing grade
			fails.push_back(*iter);
		}
		else { // student succeeded
			students.insert(students.begin(), *iter);
			*iter++; // * has a higher precedence than ++ so no parentheses needed
		}
	}
	
	students.resize(orig_size - fails.size());
	return fails;
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