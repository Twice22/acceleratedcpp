#pragma once
#ifndef _PTR_H_
#define _PTR_H_

#include <stdexcept>

template <class T>
class Ptr {
public:
	// constructors
	Ptr(): p(0), refptr(new size_t(1)) {};

	// increment the num of instance of the same object in the constructor
	Ptr(const Ptr& rhs) : p(rhs.p), refptr(rhs.refptr) { ++*refptr; };

	Ptr(T* t) : p(t), refptr(new size_t(1)) {};

	Ptr& operator=(const Ptr& rhs);
	~Ptr() {
		// we are destroying the objetc pointed by the pointers only if there is no more
		// reference to the objects
		if (--*refptr == 0) {
			delete p;
			delete refptr;
		}
	}

	// create predicate
	operator bool() const { return p; };

	// overload * and -> operator.
	// the first one return the object pointed by the pointer
	// the second return a pointer
	T& operator*() const {
		if (p)
			return *p;
		throw std::runtime_error("Unbound Ptr");
	}

	T* operator->() const {
		if (p)
			return p;
		throw std::runtime_error("Unbound Ptr");
	}

	// if the reference count is 1 (*refptr==1) we don't need to make a copy of the objet (it is already unique)
	// otherwise as make_unique is a method, it is attached to a left-hand operand object so *refptr != 0 (and hence
	// *refptr > 1). It this case we decrement the nb of ref to the object and we create another object.
	// the new object will have only one refptr (itself) so refptr = new size_t(1)
	// the new object will be copied from itself if it is already hold values, otherwise it will be default-initialize to 0
	void make_unique() {
		if (*refptr != 1) {
			--*refptr;
			refptr = new size_t(1);
			p = p ? clone(p) : 0;
		}
	}

private:
	T* p; // pointer on Object of type/class T

	// pointer on obj of type size_t
	// used to keep track of the nb of instances of a same object
	// to know when we need to free the memory
	std::size_t* refptr;
};

template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs) {
	// increment nb of instance refering to the same object
	++*rhs.refptr;

	// as we are assigning a new Object to the left hand operand,
	// we need to decrease the number of ref to the Object. If there is no
	// more reference to a object we destroy it.
	// NOTE: if the user are doing a self-assignment, the fact that we increment
	// the value pointed by pointer of the right hand side will increment it for the
	// left and side and hence --*refptr != 0, preventing from destroying the object!
	if (--*refptr == 0) {
		// if it's not the first instance
		delete p;
		delete refptr;
	}

	// copy in values from the right-hand side
	p = rhs.p;
	refptr = rhs.refptr;
	return *this;
}

template <class T>
T* clone(const T* tp) {
	return tp->clone();
}

#endif // !_PTR_H_
