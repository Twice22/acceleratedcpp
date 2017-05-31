#pragma once
#ifndef _VCAT_PIC_
#define _VCAT_PIC_

#include <algorithm>
#include <iostream>

#include "Pic_base.h"
#include "Ptr.h"

class VCat_Pic : public Pic_base {
	// friend
	friend Picture vcat(const Picture&, const Picture&);

	Ptr<Pic_base> top, bottom;
	VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) : top(t), bottom(b) {};

	w_sz width() const { return std::max(top->width(), bottom->width()); };
	h_sz height() const { return top->height() + bottom->height(); };
	void display(std::ostream&, h_sz, bool) const;

	// Answer to Q15.4
	void reframe(char t, char b, char s) {
		top->reframe(t, b, s);
		bottom->reframe(t, b, s);
	}
};

// implementing display fct;
void VCat_Pic::display(std::ostream& os, h_sz row, bool do_pad) const {
	w_sz w = 0;

	if (row < top->height()) {
		top->display(os, row, do_pad);
		w = top->width();
	}
	else if (row < height()) {
		// don't forget to offset by top->height()
		bottom->display(os, row - top->height(), do_pad);
		w = bottom->width();
	}

	if (do_pad)
		pad(os, w, width());
}

#endif