#include "stdafx.h"
#include "Str.h"

#include <cctype>
#include <stdexcept>
#include <algorithm>
#include <vector>

using namespace std;

Str& Str::operator+=(const Str& s) {
	size_type new_len = len + s.size();

	// allocate space
	iterator new_data = alloc.allocate(new_len);

	// copy left-hand operand into new_data
	uninitialized_copy(begin(), end(), new_data);

	// copy right-hand operand
	uninitialized_copy(s.begin(), s.end(), new_data + len - 1);

	// constructor null-terminated char
	alloc.construct(new_data + new_len - 1, '\0');

	// free space
	uncreate();

	// reassign new_data to data and return
	cdata = new_data;
	len = new_len;

	return *this;
};


// << operator
ostream& operator<<(ostream& os, const Str& s) {
	for (Str::size_type i = 0; i < s.size(); ++i) {
		os << s[i];
	}
	return os;
}

istream& operator>>(istream& is, Str& s) {
	vector<char> text;

	// skip whitespaces
	char c;
	while (is.get(c) && isspace(c));

	if (is) {
		do {
			text.push_back(c);
		} while (is.get(c) && !isspace(c));
		if (is) is.unget();
	}

	s = Str(text.begin(), text.end());

	return is;
}

void Str::create(size_type n, char c) {
	len = n + 1;
	cdata = alloc.allocate(len);
	std::uninitialized_fill(cdata, cdata + n, c);
	alloc.construct(cdata + n, '\0');
}

void Str::uncreate() {
	for (size_type i = len; i > 0; --i) {
		alloc.destroy(&cdata[i]);
	}
	alloc.deallocate(cdata, len);

	cdata = 0; // equal null-terminated chain
	len = 0;
}

Str::size_type Str::copy(iterator s, size_type length, size_type pos) const {
	if (pos > size()) throw out_of_range("pos > size()");
	size_t copy_len = min(length, size() - pos);
	::copy(cdata + pos, cdata + pos + copy_len, s); // use general copy fct from algorithm
	return copy_len;
}

Str operator+(const Str& lhs, const Str& rhs) {
	Str r = lhs;
	r += rhs;
	return r;
}

Str operator+(const char* lhs, const Str& rhs) {
	Str r = Str(lhs);
	r += rhs;
	return r;
}

Str operator+(const Str& lhs, const char* rhs) {
	Str r = lhs;
	r += Str(rhs);
	return r;
}

istream& getline(istream& is, Str& s, char delim) {

	vector<char> vec;

	// read chacter till they are != from delim
	char c;

	if (is) {
		while (is.get(c) && c != delim) {
			vec.push_back(c);
		}
	}
	s = Str(vec.begin(), vec.end());

	return is;
}

ostream_iterator<char>& operator<<(ostream_iterator<char>& os, const Str& s) {
	for (Str::size_type i = 0; i < s.size(); ++i) {
		os++ = s[i];
	}
	return os;
}

// Answer to Q12.11 (add substr)
Str Str::substr(size_type beg, size_type len) const {
	return Str(cdata + beg, cdata + beg + len);
}