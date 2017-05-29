#pragma once
#ifndef _STR_H_
#define _STR_H_

#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

#include "Vec.h"

class Str {
	// friend fct to access private data member;
	friend std::istream& operator>>(std::istream&, Str&);

public:
	// synonym to access size_type
	typedef Vec<char>::size_type size_type;

	// constructors
	Str() {};
	Str(size_type n, const char& c) : data(n, c) {};

	// this constructor also define a conversion operator from
	// const char* to Str.
	// Note: Constructor that takes a single argument define conversions
	Str(const char* str) {
		// don't forget we need to pass an iterator as a thir arg to copy
		std::copy(str, str + std::strlen(str), std::back_inserter(data));
	}

	// operator [];
	char& operator[](size_type i) { return data[i]; };
	const char& operator[](size_type i) const { return data[i]; };

	// Answer to Q12.10 (Change)
	template <class In>
	Str(In b, In e) {
		data = Vec<char>(b, e);
	}

	// size()
	size_type size() const { return data.size(); };

	// need to define clear() for operator>>
	void clear() { data.clear(); };

	// += operator
	Str& operator+=(const Str& s) {
		// use begin iterator from Vec.h
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

private:
	Vec<char> data;
};

// these functions are not members of Str because the right hand side is of
// a different type than the left hand side type (yet one need to be a friend
// fct!). Friend fct can be place anywhere in the class, be it after public or
// private statement it doesn't care.
std::ostream& operator<<(std::ostream&, const Str&);

// + operator
Str operator+(const Str&, const Str&);

#endif // !_STR_H_
