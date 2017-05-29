#pragma once
#ifndef _GRAD_H_
#define _GRAD_H_

#include "Core.h"

// Graduate student derived from Core Student
// They need to do a thesis
class Grad : public Core {
public:
	Grad() : thesis(0) {};
	Grad(std::istream& is) { read(is); };

	// overload read
	std::istream& read(std::istream& is);

	// overload grade (need to take into account the thesis paper)
	double grade() const;

	bool is_all_hw_done() { return (Core::is_all_hw_done() && thesis > 0.0); };

	// Answer to Q13.8
	std::string type() const { return "Graduate"; };

private:
	// no need to specify virtual as the "parent" fct is already virtual
	Grad* clone() const { return new Grad(*this); };

	double thesis;
};

// Answer to Q13.6
// We create a class derivated from Core
class PassingFailing : public Core {
public:
	// constructor
	PassingFailing() {};
	PassingFailing(std::istream& is) { read(is); };

	double grade() const; // virtual fct

	// add is_all_hw_done for pass / fail credit
	// it returns true because we don't care wether the student did the hw or not
	bool is_all_hw_done() { return true; };

	// Answer to Q13.8
	std::string type() const { return "Credit"; };

private:
	// overload virtual clone fct
	PassingFailing* clone() const { return new PassingFailing(*this); };
};

// Answer to Q13.7
// Create class for auditing student
// Auditing a course allows a student to intend a course without the benefit of having a
// grade or credits...
class Auditing : public Core {
public:
	Auditing() {};
	Auditing(std::istream& is) { read(is); };

	// redefine is_all_hw_done
	bool is_all_hw_done() { return true; }; // true because he has no assignment to do

	// redefine double grade(), return 0 because he has no grade!
	double grade() const { return 0.0; };

	// redefine how we read
	std::istream& read(std::istream&);

	// Answer to Q13.8
	std::string type() const { return "Audit"; };

private:
	Auditing* clone() const { return new Auditing(*this); };
};


#endif // !_GRAD_H_
