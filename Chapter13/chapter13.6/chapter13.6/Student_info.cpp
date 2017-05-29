#include "stdafx.h"
#include "Student_info.h"
#include "Grad.h"

using namespace std;

istream& Student_info::read(istream& is) {
	delete cp; // delete previous object if any

	char ch;
	is >> ch;

	// Answer to Q13.6
	if (ch == 'U')
		cp = new Core(is);
	else if (ch == 'P' || ch == 'F')
		cp = new PassingFailing(is);
	else if (ch == 'G') // Answer to Q13.7
		cp = new Grad(is);
	else
		cp = new Auditing(is);

	return is;
}

Student_info::Student_info(const Student_info& s) : cp(0) {
	if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s) {
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}

	return *this;
}