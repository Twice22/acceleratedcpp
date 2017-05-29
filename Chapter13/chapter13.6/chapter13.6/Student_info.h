#pragma once
#ifndef _STUDENT_INFO_
#define _STUDENT_INFO_

#include <iostream>

#include "Core.h"

// Handle class
class Student_info {
public:
	// Initialize Student using pointer on Core object
	Student_info() : cp(0) {};
	Student_info(std::istream& is) : cp(0) { read(is); };

	Student_info(const Student_info&);
	Student_info& operator=(const Student_info&);

	// destructor
	~Student_info() { delete cp; };

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

	bool is_all_hw_done() { return cp->is_all_hw_done(); };

	// Answer to Q13.8
	std::string type() const { return cp->type(); };

private:
	Core* cp; // Pointer to Core
};

#endif // !_STUDENT_INFO_
