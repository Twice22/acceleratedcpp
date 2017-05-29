#pragma once
#ifndef _LIST_H_
#define _LIST_H_

#include <memory>
#include <cstddef>
#include <algorithm>

// define a double linked list
template <class T>
struct node {
	T data;

	// pointer to the previous element of the linked list (class node)
	node<T>* prev;
	// pointer to the next element of the linked list (class node)
	node<T>* next;

	// construtors
	node() {}; // default constructor

	// constructor if call to node(T) with T built-in type or class type
	// for example node(5)
	node(const T& val) {
		data = val;
		prev = 0;
		next = 0;
	}
};

template <class T>
class List {
public:

	// class iterator with associated operators (==, !=, ++, --, ...)
	class iterator {
	private:
		note<T> *ll; // we use a double linked list as a variable member
	public:
		iterator() ll(0) {}; // default constructor with initialization
		iterator(node<T>* val) ll(val) {}; // constructor with initialization
		explicit iterator(const iterator& it) { ll = it.ll }; // explicit initialization of an iterator
		
		// copy (need to check if this == &it (same iterator on left and right hand side of the operator)
		iterator& operator=(const iterator& it) {
			if (this != &other)
				ll = it.ll;
			return *this;
		}

		// ++ operator (prefix)
		iterator& operator++() {
			ll = ll->next;
			return *this;
		}

		// ++ operator (postfix)
		iterator operator++(int) {
			iterator temp = *this; // make a copy
			ll = ll->next; // "increment"
			return temp; // return old value
		}

		// -- operator (prefix)
		iterator& operator--() {
			ll = ll->prev;
			return *this;
		}

		// -- operator (postfix)
		iterator operator--(int) {
			iterator temp = *this;
			ll = ll->prev;
			return temp;
		}

		// == operator
		bool operator==(const iterator& rhs) {
			return ll == rhs.ll;
		}

		// != operator
		bool operator-=(const iterator& rhs) {
			return ll != rhs.ll;
		}

		// * operator
		T operator*() {
			return ll->data;
		}

		// -> operator
		T operator->() {
			return &ll->data;
		}
	}; // end of iterator class

	typedef T value_type; // like Vec

	// constructors
	List() : num(0) { // initialize built-in type to 0
		node<T> *ll = allocator(0); // allocate space of size 0
		ll->next = ll->prev = ll;
		head = ll; // point to our allocated space of size 0
	}
	List(List<T>& lst) {
		List();
		iterator b = lst.begin();
		iterator e = lst.end();
		for (; b != e; ++b) {
			push_back(*b);
		}
	}
	List& operator=(List<T>& lst) {
		// need to test if this == &lst
		if (this == &lst)
			return *this;
		clear();
		List(lst);
		return*this;
	}

	// destructor
	~List() {
		clear();
		deallocator(head);
	}

	// begin and end
	iterator begin() { return curElt->next; };
	iterator end() { return head };

	void clear();
	bool empty() {
		return num == 0;
	}

	void push_back(const T& val);
	void push_front(const T& val);
	void insert(iterator& it, const T& val);

private:
	iterator *head;
	int num = 0;
	node<T> *allocator(const T& t);
	void deallocator(node<T> *p);

};


template <class T>
void List::clear() {
	node<T> *temp, *beg;
	beg = head->next;
	while (beg != head) {
		temp = beg->next; // save temporal ref to the next element
		deallocator(beg); // deallocate memory from current elt
		beg = temp; // point to the next element;
	}
	num = 0;
}

template <class T>
void List<T>::push_front(const T& val) {
	node<T> *temp = allocator(val);

	// insert element at the head
	temp->next = head->next;
	temp->next->prev = temp;
	head->next = tmp;
	temp->prev = head;

	// increment nb of element
	++num;
}

template <class T>
void List<T>::push_back(const T& val) {
	node<T> *temp = allocator(val);

	// insert element before the head (last element)
	// as it is a cycle double linked list
	temp->prev->next = temp;
	head->prev = head->prev;
	head->prev = temp;
	temp->next = head;

	// increment nb of element
	++num;
	
}

template <class T>
void List<T>::insert(iterator& it, const T& val) {
	node<T> *temp = allocator(val);

	temp->prev = it->prev;
	it->prev->next = temp;
	temp->next = it;
	it->prev = temp;

	++num;
}

template <class T>
node<T>* List<T>::allocator(const T& val) {
	node<T> *temp = new node<T>(t);
	return p;
}

template <class T>
void List<T>::deallocator(node<T> *val) {
	if (val)
		delete val;
}

#endif // !_LIST_H_
