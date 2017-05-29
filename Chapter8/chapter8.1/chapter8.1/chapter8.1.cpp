// chapter8.1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime>

#include "grade.h"
#include "Student_info.h"
#include "classify.h"
#include "did_all_hw.h"
#include "analysis.h"

using namespace std;


int main()
{

	// students that did or didn't do all their homework
	vector<Student_info> did, didnt;

	// read the student record and partition them
	Student_info student;
	while (read(cin, student)) {
		did.push_back(student);
	}

	didnt = extract_didnt(did);

	// verify that the analyses will show us something
	if (did.empty()) {
		cout << "No student did all the homework!" << endl;

		system("pause");
		return 1;		
	}
	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;

		system("pause");
		return 1;		
	}

	// do analyses
	write_analysis(cout, "median", grade_aux, did, didnt);
	write_analysis(cout, "average", average_grade, did, didnt);
	write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);


	system("pause");
	return 0;
}



