#pragma once
#ifndef _FRAME_PIC_
#define _FRAME_PIC_

#include <iostream>
#include <string>

#include "Pic_base.h"
#include "Ptr.h"

class Frame_Pic : public Pic_base {
	// friend to access private member
	friend Picture frame(const Picture&);

	Ptr<Pic_base> p;
	// Answer to Q15.2
	char topc, botc, sidec;

	// Answer to Q15.3
	Frame_Pic(const Ptr<Pic_base>& pic) : p(pic), topc('*'), botc('*'), sidec('*') {};

	h_sz height() const { return p->height() + 4; };
	w_sz width() const { return p->width() + 4; }; // 4 for padding + * ("* " and " *")
	void display(std::ostream&, h_sz, bool) const;

	// Answer to Q15.4
	void reframe(char t, char b, char s) {
		// we could have a frame in a frame don't forget!
		// the recursion will stop because at the end we would
		// call reframe from String_Pic!
		p->reframe(t, b, s);
		topc = t; botc = b, sidec = s;
	}
};

// implementing display fct;
void Frame_Pic::display(std::ostream& os, h_sz row, bool do_pad) const {

	if (row >= height() || row < 0) { // Add row < 0 to Answer Q15.5

		// out of range
		if (do_pad)
			pad(os, 0, width());
	}
	else if (row == 0) {
		// top border and bottom border have *****...
		os << std::string(width(), topc);
	}
	else if (row == height() - 1) {
		// Answer to Q15.2
		os << std::string(width(), botc);
	}
	else if ( row == 1 || row == height() - 2) {
		// second and second to last have "*     *"
		os << sidec;
		pad(os, 1, width() - 1);
		os << sidec;
	}
	else { // "* " + text + " *"
		os << sidec << " ";
		// don't forget the minus 2
		// because he have padding = 2 at the top
		// one for "*" and one for whitespace
		p->display(os, row - 2, true); // true to pad if text to "small"
		os << " " << sidec;
	}
}

#endif