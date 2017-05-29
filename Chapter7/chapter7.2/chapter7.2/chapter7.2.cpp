// chapter7.2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>

#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{

	map<string, int> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all the students' data
	// students contains all the student records read so far
	// maxlen contains the length of the longest name in students
	while (read(cin, record)) {
		// find length of longest name
		maxlen = max(maxlen, record.name.size());
		++students[record.total];
	}

	// write the grades and number of students
	for (map<string, int>::const_iterator i = students.begin(); i != students.end(); ++i) {
		cout << i->first << ": " << i->second << " student(s)" << endl;
	}

	system("pause");
	return 0;
}

