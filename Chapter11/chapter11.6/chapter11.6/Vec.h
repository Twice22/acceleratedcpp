#pragma once
#ifndef _VEC_H_
#define _VEC_H_

#include <memory>
#include <algorithm>
#include <cstddef>

template <class T>
class Vec {
public:
	/*         typedef to simplify notations
	These typedefs can be used by the users and will
	allow us to hide the implementation details of our class
	*/

	// pointer to T is defined as an iterator (similarly to the vector class from std)
	typedef T* iterator;
	typedef const T* const_iterator;

	// synonyms for reference
	typedef T& reference;
	typedef const T& const_reference;

	// synonyms for T (value_type), can be char, int, double,...
	typedef T value_type;
	typedef size_t size_type;

	// type for substracting one iterator from another
	typedef std::ptrdiff_t difference_type;

	/*          Public interface       */
	// default constructor that use private method create() defined below
	Vec() { create(); };

	// explicit keyword will tell the compiler to call this constuctor only
	// if it was explicitly called! For example:
	// Vec<int> vi(100); //explicit call
	// Vec<int> vi = 100; // implicitly construct the Vec and copy it ti vi
	// Moreover we used a default argument for the second paramater. Hence we can
	// call our method either by doing:
	// Vec(100) or Vec(100, 5) for example.
	// The second argument will call the constructor of T to generated data by default.
	explicit Vec(std::size_t n, const T& val = T()) { create(n, val); };

	// define [] operator that user use when they write v[i] = 5; (Vec v = Vec(0);)
	// return reference to the element stored in data[i], that will allow the user
	// to write through the index or read from it
	T& operator[](size_type i) { return data[i]; };

	// define same operator for read only access
	// if we declared a const Vec<int> vc = Vec(100,5); then, when accesing the data
	// the program will use this operator. Indeed the fact that Vec is const allow
	// to overload the operator method.
	const T& operator[](size_type i) const { return data[i]; };

	// Copy constructor (it takes a const reference as input because it shouldn't
	// change the object from which we want to make the copy)
	// We call a private utility method from our class to create a copy. Note that
	// here we what to copy all the content of our vector to another memory space!
	// we DON'T want to copy the pointer... that will result in referencing the same
	// object from 2 different variable names.
	Vec(const Vec& v) { create(v.begin(), v.end()); };

	// Assignment operator (=) should return a copy of the input (but we should ensure
	// that the input is not our object itself (Vec c = Vec(100,5); v = v; ) because we need to deallocate
	// the memory before reallocating it
	Vec& operator=(const Vec&);

	// Dectructor (begining with a tild ~, doesn't have a return type) will release the memory
	// Here we are calling a private method uncreate() to free the memory. This function will be
	// called for example when we return from a fct using our Vec class
	~Vec() { uncreate(); };

	// add size method. As taking the size of the Vec doesn't change the Vec
	// we define it as const
	size_type size() const { return avail - data; };

	// method end() and begin() that return a reference similarly to the vector class from std
	iterator end() { return avail; };
	const_iterator end() const { return avail; };

	iterator begin() { return data; };
	const_iterator begin() const { return data; };

	// add push_back to append element to the array. When we want to add an element to the array
	// we need to allocated new space to hold one more element. Then we need to copy the existing
	// elements into this new place and append the newly created element we wante to push. If the
	// user uses push_back many times it will be very expensive. As a workaround we will create 2
	// times more space for our array than the size our user ask for. Hence if the user uses:
	// Vec vc = Vec(100, 5); then we will create an array with enough space to hold 200 elements.
	void push_back(const T& val) {
		if (avail == limit) {
			grow(); // expand calling our private grow method if there is not enough space left
		}
		unchecked_append(val); // append the new element
	};

	// Answer to Q11.6 (add erase)
	iterator erase(iterator);
	void clear() { uncreate(); };

private:
	iterator data; // remember it's a pointer to a value type T
	iterator avail; // pointer to one past the last constructed element
	iterator limit; // pt to (one past) the last available element

					// facilities for memory allocation
	std::allocator<T> alloc; // it relies on <memory> header

							 // allocate and initialize the underlying array
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// destroy the elements in the array and free the memory
	void uncreate();

	// support functions for push_back
	void grow();
	void unchecked_append(const T&);
};

// Need to define private classes here

template <class T>
void Vec<T>::create() {
	data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val) {
	data = alloc.allocate(n); // allocate n element and return pointer to the first element
	limit = avail = data + n; // change the pointers
	std::uninitialized_fill(data, limit, val); // copy val into the sequence of uninitialized elements
}

template <class T>
void Vec<T>::create(const_iterator b, const_iterator e) {
	data = alloc.allocate(e - b);

	// copy sequence delimited by the 2 first arguments into its third argument
	// return a pointer to the (one past) the last element that is initialized
	limit = avail = std::uninitialized_copy(b, e, data);
}

template <class T>
void Vec<T>::uncreate() {
	if (data) {
		// destroy in reverse order the elements that were contructed
		iterator it = avail;
		while (it != avail) {
			alloc.destroy(--it);

			// return all the space that was allocated
			// take a pointer to the first element of the memory to free
			// and an integral value that indicates how many elements are to be freed
			alloc.deallocate(data, limit - data);
		}
		data = limit = avail = 0;
	}
}

template <class T>
void Vec<T>::grow() {
	// allocate twice as much space when growing
	// ptrdiff_t(1) is the size of the difference of 2 pointers.
	// we are taking the max here because Vec can be empty
	size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

	// allocate new space and copy existing elements to the new space
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	// return the old space
	uncreate();

	// reset the pointers to point to the newly allocated space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
	// construct constructs a single object (val) in unitialized storage;
	// we increment avail
	alloc.construct(avail++, val);
}

// As we are difining a template member fct outside the class header
// we need to signale to the compiler that we are defining a template.
// also we need to precise the return type which is Vec<T>&. We need
// to provide the T here because we are outside of the scope of the class.
template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
	// this is a pointer to the object of which the member
	// function is operating. Hence the type of this is Vec* here

	// check for self-assignment
	if (this != &rhs) {
		// free the array in the left-hand side
		uncreate();

		// copy element from the right-hand side
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

// Add erase
template <class T>
T* Vec<T>::erase(iterator it) {
	// copy from begin to it and from it+1 to end (not to most efficient way)
	iterator new_data = alloc.allocate(avail - data - 1);
	iterator tmp = std::uninitialized_copy(data, it, new_data);
	iterator new_avail = std::uninitialized_copy(it+1, avail, tmp);

	uncreate();

	data = new_data;
	avail = new_avail;

	// return position immediately after the erasure
	return (avail+1);
}

#endif // !_VEC_H_
