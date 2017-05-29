#include "stdafx.h"
#include "extract_fails.h"

using namespace std;


Student_infos extract_fails(Student_infos& students) {

	Student_infos fails;
	Student_infos::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fails.push_back(*iter);
			iter = students.erase(iter);
		}
		else {
			++iter;
		}
	}

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