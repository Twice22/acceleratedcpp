#include "stdafx.h"
#include "extract_fails.h"

using namespace std;

vector<Student_info> extract_fails(vector<Student_info>& students) {

	vector<Student_info> fails;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) { // failing grade
			fails.push_back(*iter);
			iter = students.erase(iter);
		}
		else {
			++iter;
		}
	}
	return fails;
}


list<Student_info> extract_fails(list<Student_info>& students) {

	list<Student_info> fails;
	list<Student_info>::iterator iter = students.begin();

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

void display_v(const vector<Student_info>& vec, string s, string::size_type maxlen) {

	cout << s << endl;
	for (vector<Student_info>::size_type i = 0; i != vec.size(); ++i) {
		// write the name, padded on the right to maxlen + 1 characters
		cout << vec[i].name
			<< string(maxlen + 1 - vec[i].name.size(), ' ');

		try {
			double final_grade = grade(vec[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
}

void display_l(const list<Student_info>& vec, string s, string::size_type maxlen) {

	cout << s << endl;

	list<Student_info>::const_iterator iter = vec.begin();

	while (iter != vec.end()) {
		// write the name, padded on the right to maxlen + 1 characters
		cout << iter->name
			<< string(maxlen + 1 - iter->name.size(), ' ');

		try {
			double final_grade = grade(*iter);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
}