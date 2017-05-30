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

protected:
	// no need to specify virtual as the "parent" fct is already virtual
	Grad* clone() const { return new Grad(*this); };

private:
	double thesis;
};

#endif // !_GRAD_H_
