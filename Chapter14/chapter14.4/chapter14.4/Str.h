#pragma once
#ifndef _STR_H_
#define _STR_H_

#include <algorithm>
#include <string>
#include <iterator>

#include "Ptr.h"
#include "Vec.h"


class Str {
	friend std::istream& operator>>(std::istream& is, Str& s);
public:
	// interface
	typedef Vec<char>::size_type size_type;

	// constructor
	Str() : data(new Vec<char>) {};
	Str(const char* cp) : data(new Vec<char>) {
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(*data));
	}
	Str(size_type n, char c) : data(new Vec<char>(n,c) ) {}
	template <class In>
	Str(In b, In e) {
		std::copy(b, e, std::back_inserter(*data));
	}

	// [] operator
	char& operator[](size_type i) {
		data.make_unique();
		return (*data)[i];
	}

	// [] operate with read-only
	const char& operator[](size_type i) const {
		return (*data)[i];
	}


	// to get the size of the "string"
	size_type size() const {
		return data->size();
	};

	// += operator
	Str& operator+=(const Str& rhs) {
		data.make_unique();
		std::copy(rhs.data->begin(), rhs.data->end(), std::back_inserter(*data));
		return *this;
	}

private:
	Ptr< Vec<char> > data;
};

// output/input stream
std::ostream& operator<<(std::ostream& os, const Str& s) {
	for (Str::size_type i = 0; i < s.size(); ++i) {
		os << s[i];
	}
	return os;
}




std::istream& operator>>(std::istream& is, Str& s) {

	s.data->clear();

	// skip whitespaces
	char c;
	while (is.get(c) && isspace(c));

	if (is) {
		do {
			s.data->push_back(c);
		} while (is.get(c) && !isspace(c));

		if (is)
			is.unget();
	}
	return is;
}

template<>
Vec<char>* clone(const Vec<char>* vp) {
	return new Vec<char>(*vp);
}

#endif // !_STR_H_
