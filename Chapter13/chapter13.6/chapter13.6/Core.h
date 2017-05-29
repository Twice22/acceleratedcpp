#ifndef _CORE_H_
#define _CORE_H_

#include <string>
#include <vector>
#include <iostream>

// include function prototype because we don't have a read_hw.h file
std::istream& read_hw(std::istream& is, std::vector<double>& hw);

class Core {
	friend class Student_info; // Student_info need to be friend to access the protected clone fct
public:
	// default constructor
	Core() : midterm(0), final(0) {};

	// Construct student from input stream
	Core(std::istream& is) { read(is); };

	// read info from input stream to create student
	std::istream& read(std::istream& is);

	// getter to n (name of student)
	std::string name() const { return n; };

	// getter to compute and return grade
	// virtual provide run-time selection. If we call grade on
	// a ref or pointer to Core object it will compute obj.Core::grade()
	// if obj is a ref/pointer to a Grad object it will compute obj.Grad::grade()
	// Note: virtual fct are inherited
	virtual double grade() const;

	// Virtual Core destructor. Virutal needed to know what kind of object to
	// destroy. If we destroy Grad (derived from Core) we need to free more space.
	virtual ~Core() {};

	// Answer to Q13.5 (virtual so we can redifine it in Grad)
	virtual bool is_all_hw_done() { return std::find(homework.begin(), homework.end(), 0.0) == homework.end(); };

	// information about type of student (Answer to Q13.8)
	virtual std::string type() const { return "Undergraduate"; };

protected: // so derived classes can access these members
		   // read file to initialize student
	std::istream& read_common(std::istream& is);

	// data (name, midterm, final and homework grades)	
	double midterm, final;
	std::vector<double> homework;

	// creates new object that holds copies of the values in the original
	// defined it to be a virtual function, so if we are calling it from a
	// class derived from Core we will call the appropriate clone function
	virtual Core* clone() const { return new Core(*this); }; // use Core copy constructor
															 // as we didn't define a Core copy constructor, it will generate one by default.
	// Answer to Q13.7
	// n need to be protected so Auditing (derivated class can access it)
	// it is useful for the read method from Auditing class
	std::string n;
private:
};

bool compare_grades(const Core&, const Core&);

// Answer to Q13.4
std::string letter_grade(double);

#endif // !_CORE_H_
