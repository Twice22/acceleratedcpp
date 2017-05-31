#pragma once
#ifndef _PICTURE_
#define _PICTURE_

#include <string>
#include <vector>

#include "Frame_Pic.h"
#include "HCat_Pic.h"
#include "VCat_Pic.h"
#include "String_Pic.h"
#include "Pic_base.h"
#include "Ptr.h"

class Picture {
	// friends to access private member
	friend Picture frame(const Picture&);
	friend Picture vcat(const Picture&, const Picture&);
	friend Picture hcat(const Picture&, const Picture&);
	friend std::ostream& operator<<(std::ostream&, const Picture&);

public:
	Picture(const std::vector<std::string>& = std::vector<std::string>());
	
	// Answer to Q15.4 (reframe act directly on the Picture so we make
	// it a member fct)
	void reframe(char t, char b, char s) {
		p->reframe(t, b, s);
	}

private:
	Picture(Pic_base* ptr) : p(ptr) {}; // constructor that converts from ptr to Picture (*)
	Ptr<Pic_base> p;
};

// Picture is our interface. Here we would like to be able to frame,
// concat vertically/horizontally and display it on output stream
Picture frame(const Picture&);
Picture vcat(const Picture&, const Picture&);
Picture hcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

Picture::Picture(const std::vector<std::string>& v) : p(new String_Pic(v)) { }

// Implementing fct;
Picture frame(const Picture& pic) {
	return new Frame_Pic(pic.p); // use (*) to return a Picture
}

Picture vcat(const Picture& top, const Picture& bot) {
	return new VCat_Pic(top.p, bot.p);
}

// beware to write hcat that call Hcat !!!
Picture hcat(const Picture& left, const Picture& right) {
	return new HCat_Pic(left.p, right.p);
}

std::ostream& operator<<(std::ostream& os, const Picture& pic) {
	const Pic_base::h_sz size = pic.p->height();
	for (Pic_base::h_sz i = 0; i < size; ++i) {
		pic.p->display(os, i, false);
		os << std::endl;
	}
	return os;
}

#endif