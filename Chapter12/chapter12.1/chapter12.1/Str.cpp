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
	data = new_data;
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

istream& operator>>(std::istream& is, Str& s) {
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
	data = alloc.allocate(len);
	std::uninitialized_fill(data, data + n, c);
	alloc.construct(data + n, '\0');
}

void Str::uncreate() {
	for (size_type i = len; i > 0; --i) {
		alloc.destroy(&data[i]);
	}
	alloc.deallocate(data, len);

	data = 0; // equal null-terminated chain
	len = 0;
}