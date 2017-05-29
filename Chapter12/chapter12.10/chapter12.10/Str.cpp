#include "stdafx.h"

#include <cctype>
#include <iostream>
#include <iterator>

#include "Str.h"


using namespace std;

ostream& operator<<(ostream& os, const Str& s) {
	for (Str::size_type i = 0; i < s.size(); ++i) {
		os << s[i];
	}
	return os;
}

istream& operator>>(istream& is, Str& s) {

	// erase date if str holds data
	s.data.clear(); // need this declaration to be a friend to access private data member

	char c;
	// while it is a space keep reading character
	// and to nothing --> that allows us to discard char
	while (is.get(c) && isspace(c))
		;

	// construct a string that represent a word between
	// two non whitespace chars
	do {
		s.data.push_back(c); // need this declaration to be a friend to access private data member
	} while (is.get(c) && !isspace(c));

	// remove space at the end if it was one
	if (is) {
		is.unget();
	}

	return is;

}

// define operator+ using operator+=.
Str operator+(const Str& s1, const Str& s2) {
	Str s = s1; // invoke Str copy constructor
	s += s2; // use operator+=
	return s;
}