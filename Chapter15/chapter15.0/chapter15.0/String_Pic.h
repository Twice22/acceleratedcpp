#pragma once
#ifndef _STRING_PIC_
#define _STRING_PIC_

#include <vector>
#include <algorithm>
#include "Pic_base.h"

// This class will actually concrete a String_Pic. We will then
// need to construct a string as a vector<char> and implement
// virtual functions of the abstract class from which it derives.

class String_Pic : public Pic_base {
	friend class Picture;

	h_sz height() const { return data.size(); };
	w_sz width() const;

	String_Pic(const std::vector<std::string>& v) :data(v) {};

	void display(std::ostream&, h_sz, bool) const;

	// Answer to Q15.4
	void reframe(char, char, char) {}

private:
	std::vector<std::string> data;
};


void String_Pic::display(std::ostream& os, h_sz row, bool do_pad) const {
	w_sz start = 0;

	if (row < height()) {
		os << data[row];
		start = data[row].size();
	}

	if (do_pad) // need to define a pad fct (static in Pic_base)
		pad(os, start, width());
}

Pic_base::w_sz String_Pic::width() const {
	Pic_base::w_sz size = 0;
	for (Pic_base::h_sz i = 0; i < height(); ++i) {
		size = std::max(data[i].size(), size);
	}
	return size;
}

#endif