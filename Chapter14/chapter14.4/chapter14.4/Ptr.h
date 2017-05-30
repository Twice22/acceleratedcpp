#pragma once
#ifndef _PTR_H_
#define _PTR_H_

template <class T>
class Ptr {
public:
	// constructors
	Ptr() : p(0), refptr(new size_t(1)) {};
	Ptr(const Ptr& h) : p(h.p), refptr(h.refptr) {};
	Ptr(T* t) : p(t), refptr(new size_t(1)) {};

	// copy constructor
	Ptr& operator=(const Ptr& rhs) {
		++*rhs.refptr; // augment nb of ref to object
		
		if (--*refptr == 0) {
			delete p;
			delete refptr;
		}

		// copy value
		p = rhs.p;
		refptr = rhs.refptr;
		return *this;
	}

	// destructor
	~Ptr() {
		if (--*refptr == 0) {
			delete p;
			delete refptr;
		}
	}

	operator bool() const { return p; }

	T& operator*() const {
		if (p)
			return *p;
		throw std::runtime_error("Ptr uninitialized!");
	}

	T* operator->() const {
		if (p)
			return p;
		throw std::runtime_error("Ptr uninitialized!");
	}

	// make_unique transform a ref to a copy that has its own objects
	void make_unique() {
		if (*refptr != 1) { // if 1 we cannot make it unique!
			--*refptr; // decrement nb of ref to the rhs object
			refptr = new size_t(1);
			p = p ? clone(p) : 0;
		}
	}

private:
	T* p;
	std::size_t* refptr;
};


template <class T>
T* clone(const T* tp)
{
	return tp->clone();

}

#endif