// chapter13.2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Core.h"
#include "Grad.h"
#include "Student_info.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	Core* p1 = new Core;
	Core* p2 = new Grad;
	Core s1;
	Grad s2;

	// p1 is a pointer to Core so it will call Core::grade()
	try {
		p1->grade();
	}
	catch (domain_error e) {}
	

	// p1 is a pointer to Core so it will call Core::name()
	p1->name();

	// p2 is a pointer to Core but we initialized a Grad object
	// so it will actually call Grad::name() because grade() is a virtual fct
	// Note: because in Grad::grad we call Core::grad it will actually call
	// Grad::grad()
	// Core::grad()
	try {
		p2->grade();
	}	
	catch (domain_error e) {}

	// Core::name() (no choice as name is only defined in Core and it is not a virtual fct)
	p2->name();

	// s1 is a Core object so it is statically bound to Core::grade();
	try {
		s1.grade();
	} 
	catch (domain_error e) {}
	

	// Core::name() (no choice as name is only defined in Core and it is not a virtual fct)
	s1.name();

	// Core::name() (no choice as name is only defined in Core and it is not a virtual fct)
	s2.name();

	// same idea: Grad::grade();
	// and as in Grad::grade() we are calling Core::grade(), it will also call
	// Core::grade() just after
	try {
		s2.grade();
	}
	catch (domain_error e) {}
	

	system("pause");
	return 0;
}

