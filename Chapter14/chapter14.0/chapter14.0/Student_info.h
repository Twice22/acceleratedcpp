#pragma once
#ifndef _STUDENT_INFO_
#define _STUDENT_INFO_

#include <iostream>
#include <istream>
#include <stdexcept>

#include "Core.h"
#include "Ptr.h"

// Handle class
class Student_info {
public:
	// Initialize Student using pointer on Core object
	Student_info() : cp(0) {};
	Student_info(std::istream& is) : cp(0) { read(is); };

	// copy, assign, destructor no longer needed

	std::istream& read(std::istream& is);

	std::string name() const {
		if (cp) return cp->name();
		else throw std::runtime_error("uninitialized student");
	}

	double grade() const {
		if (cp) return cp->grade();
		else throw std::runtime_error("uninitialized student");
	}

	static bool compare(const Student_info& s1, const Student_info& s2) {
		return s1.name() < s2.name();
	}

private:
	Ptr<Core> cp; // replace Core* cp by Ptr<Core> cp
};

#endif // !_STUDENT_INFO_