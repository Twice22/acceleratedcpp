// chapter6.0.cpp : définit le point d'entrée pour l'application console.
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
#include "extract_fails.h"
#include "algorithms.h"
#include "did_all_hw.h"
#include "analysis.h"

using namespace std;

void test_algo() {
	string s = "click ici: http://my_url/test/ ou click la: ftp://hello.com!";
	vector<string> urls = find_urls(s);

	// display
	for (vector<string>::const_iterator it = urls.begin(); it != urls.end(); ++it) {
		cout << (*it) << endl;
	}
}


int main()
{
	//test_algo();
	
	// students that did or didn't do all their homework
	vector<Student_info> did, didnt;

	// read the student record and partition them
	Student_info student;
	while (read(cin, student)) {
		if (did_all_hw(student)) {
			did.push_back(student);
		}
		else {
			didnt.push_back(student);
		}
	}

	// verify that the analyses will show us something
	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
		system("pause");
	}
	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
		system("pause");
	}

	// do analyses
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);


	system("pause");
    return 0;
}

