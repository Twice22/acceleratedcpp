// chapter10.0.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream> // cout endl
#include <fstream> // ifstream
#include <string> // getline

using namespace std;

/*
int main(int argc, char **argv)
{
	int fail = 0;
	// i = 0 refers to the program's name
	for (int i = 1; i < argc; i++) {
		ifstream in(argv[i]);
		if (in) {
			string s;
			while (getline(in, s)) {
				cout << s << endl;
			}
		}
		else {
			cout << "file " << argv[i] << "doesn't exist" << endl;
			++fail;
		}
	}

	return fail;
}
*/

string letter_grade(int g) {
	static const int grade[] = { 97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0 };
	static const char* letter[] = { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };

	static const size_t size = sizeof(grade) / sizeof(*grade);

	for (int i = 0; i < size; i++) {
		if (g >= grade[i]) return letter[i];
	}

	return "\?\?\?";
}


int main() {
	/*
	ifstream infile("tata.txt");
	ofstream outfile("tata2.txt");

	string s;

	while (getline(infile, s)) {
		outfile << s << endl;
	}
	*/

	string letter = letter_grade(78);
	cout << "grade: " << letter << ", expected: C+" << endl;

	system("pause");
	return 0;
}
