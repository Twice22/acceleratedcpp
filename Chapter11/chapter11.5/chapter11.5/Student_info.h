#pragma once
#ifndef STUDENT_INFO
#define STUDENT_INFO

#include <iostream>
#include <string>
#include <vector>

class Student_info {
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;

	// Answer to 11.5
	static int nb_create, nb_copy, nb_assign, nb_destroy;
	void print(const std::string&);
	void clone(const Student_info&);
public:
	Student_info(); // construct an empty Student_info object
	Student_info(std::istream&); // construct a Student_info object based on the input steam
	
	// Answer to 11.5
	Student_info(const Student_info&);
	Student_info& operator=(const Student_info&);
	
	std::string name() const { return n; };
	std::istream& read(std::istream&);
	double grade() const;
	bool valid() { return !homework.empty(); };

	// Add Destructor for 11.5
	~Student_info() { 
		nb_destroy++;
		print("destroy");
	}
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);


#endif