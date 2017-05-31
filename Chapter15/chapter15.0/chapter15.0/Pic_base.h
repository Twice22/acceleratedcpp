#pragma once
#ifndef _PIC_BASE_
#define _PIC_BASE_

#include <vector>
#include <string>

#include "Picture.h"

// Pic_base is our abstract class from which we derive 4 children classes
// According to Picture.h, we want to display the picture so we will need
// a function to display the result of our Picture (be it vcat, frame or hcat picture)
// the things that we will display depend on the row number (do we want to display a
// * or blank follow by text or * follow by blanks ?) and the height (because if we
// concatenate 2 picture with one being higher than the other we might want to know
// the height so we can pad accordingly). So we need a height/width member and a display

class Picture;

class Pic_base {
	// friend to access private variables
	friend std::ostream& operator<<(std::ostream&, const Picture&);
	// had children classes because TODO
	friend class Frame_Pic;
	friend class HCat_Pic;
	friend class VCat_Pic;
	friend class String_Pic;

	// add friend Picture (Q15.4)
	friend class Picture;

	typedef std::vector<std::string>::size_type h_sz;
	typedef std::string::size_type w_sz;

	// pure (pure because initialized to 0) virtual fcts --> Abstract class
	virtual h_sz height() const = 0;
	virtual w_sz width() const = 0;
	virtual void display(std::ostream& os, h_sz, bool) const = 0;

	// Answer to Q15.4
	virtual void reframe(char, char, char) = 0;

protected: // so children classes can access it
	// static pad function
	static void pad(std::ostream& os, w_sz beg, w_sz end) {
		for (Pic_base::w_sz i = beg; i != end; ++i) {
			os << " ";
		}
	}

public:
	// virtual --> destruction is handle by children classes 
	virtual ~Pic_base() {}; 
};

#endif