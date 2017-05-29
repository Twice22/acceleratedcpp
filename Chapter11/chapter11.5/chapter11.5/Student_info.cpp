#include "stdafx.h"
#include "Student_info.h"
#include "grade.h"

using namespace std;

// Initialize static variable outside the class
int Student_info::nb_create = 0;
int Student_info::nb_copy = 0;
int Student_info::nb_assign = 0;
int Student_info::nb_destroy = 0;

bool compare(const Student_info& s1, const Student_info& s2) {
	return s1.name() < s2.name();
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		double n;

		// get rid of previous content
		hw.clear();

		// read homework grades
		while (in >> n) {
			hw.push_back(n);
		}

		// clear the stream so that the ouput will work for the next student
		in.clear();
	}
	return in;
}

// Constructor with a sequence of constructor initializers
Student_info::Student_info() : midterm(0), final(0) {
	// Answer to 11.5: Add call to print()
	nb_create++;
	print("create");
}

// Constructor that read from input stream
Student_info::Student_info(istream& in) {
	nb_copy++;
	print("copy");
	read(in);
};

istream& Student_info::read(istream& in) {
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

double Student_info::grade() const {
	return ::grade(midterm, final, homework);
}

// Answer to 11.5
Student_info::Student_info(const Student_info& oStudent) {
	nb_copy++;
	print("copy");
	clone(oStudent);
}

Student_info& Student_info::operator=(const Student_info& oStudent) {
	nb_assign++;
	print("assign");
	if (this != &oStudent) 
		clone(oStudent);
	return *this;
}

// Answer to 11.5
void Student_info::clone(const Student_info& oStudent) {
	n = oStudent.n;
	midterm = oStudent.midterm;
	final = oStudent.final;
	homework = oStudent.homework;
}

void Student_info::print(const string& s) {
	cout << name() << " " << s << endl;
	cout << nb_create << " creation(s)" << endl;
	cout << nb_copy << " copie(s)" << endl;
	cout << nb_assign << " assignment(s)" << endl;
	cout << nb_destroy << " destroy(s)" << endl;
	cout << endl;
}