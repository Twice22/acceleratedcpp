// chapter11.0.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Vec.h"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Answer to 11.1
/*
As we didn't defined a copy constructor, an assignment operator, or a destructor
the compiler will synthesize the copy constructor, assignment operator, and/or
destructor. The synthetized operations are defined recursively. Each synthesized
operator recursively applies the appropriate operation for the data members of the
class. For example, here the copy constructor will copy four data (2 doubles directly)
and it will invokes the string and vector copy constructors to copy the name and homework
members respectively. That is enough to ensure that the data will be copied and will not
reference the data from which we made the copy.
*/

// Answer to 11.2
/*
This class didn't define a default constructor, so the compiler will synthesize a default
constructor (the constructor that takes no parameters). Hence it will construct an instance of
our class using the default constructors of its members. While using the default constructor of
a vector or a string class (name, homework) make no problem, the double members (built-in type)
won't call any constructor and so will be initialize with whatever values the compiler finds in
the available memory. To avoid this we need to initialize built-in type members using a constructor!
*/

// Answer to 11.3
/*
If we initialize a variable (variable-type variable-name = ...) then the copy constructor will be
called. When we assign a value to a variable (variable-name = value) then we use the operator=. For
the Student_info, as we didn't provide any constructor operator, the compiler will synthesized a
default operator. This synthesize operators:
- for built-in types: copy directly the value (midterm, final)
- for other members: it will invoke the copy constructors (name, homework) of each members.
*/

// Answer to 11.4
/*
The destructor for built-in types has no work to do - even if the type is a pointer. So the destructor
won't need to destroy the 2 doubles: midterm, final. It will then destroy the string and vector that are
of class type. Yet, destroying a pointer through the default destructor won't free the space at which the
pointer points!
*/

int main()
{

	// test initialization
	Vec<double> vec;

	// test push_back
	cout << "Enter your grades: ";
	double g;
	while (cin >> g)
		vec.push_back(g);

	// test self assignment
	//vec = vec;

	// test copy
	Vec<double> vec2;
	vec2 = vec;

	// test the fact that if we operate on vec2 copied from vec
	// it won't change vec
	sort(vec2.begin(), vec2.end());

	// test iterator
	for (Vec<double>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// test operator[]
	for (Vec<double>::size_type i = 0; i < vec2.size(); ++i) {
		cout << vec2[i] << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

