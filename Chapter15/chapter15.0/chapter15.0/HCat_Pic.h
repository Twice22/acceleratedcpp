#pragma once
#ifndef _HCAT_PIC_
#define _HCAT_PIC_

#include <algorithm>
#include <iostream>

#include "Pic_base.h"
#include "Ptr.h"

class HCat_Pic : public Pic_base {
	// friend
	friend Picture hcat(const Picture&, const Picture&);

	Ptr<Pic_base> left, right;
	HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) : left(l), right(r) {};

	w_sz width() const { return (right->width() + left->width()); };
	h_sz height() const { return std::max(left->height(), right->height()); };
	void display(std::ostream&, h_sz, bool) const;

	// Answer to Q15.4
	void reframe(char t, char b, char s) {
		left->reframe(t, b, s);
		right->reframe(t, b, s);
	}
};

// implementing display for Hcat_Pic
void HCat_Pic::display(std::ostream& os, h_sz row, bool do_pad) const {
	// don't forget to pad if right picture is higher than left one

	// Answer to Q15.5
	h_sz shift_l = (height() - left->height()) / 2;
	h_sz shift_r = (height() - right->height()) / 2;

	left->display(os, row - shift_l, do_pad || row > right->height());
	right->display(os, row - shift_r, do_pad);
}

#endif