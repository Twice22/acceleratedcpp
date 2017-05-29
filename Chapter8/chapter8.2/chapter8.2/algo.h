#pragma once
#ifndef _ALGO_
#define _ALGO_

#include <algorithm>
#include <iterator>

// I was confusing about my_equal, but because I've forgot the definition
// of the equal function. It tests if the elements in the seq denoted by
// the input iterators b and e are equal to the elements in a seq of the
// same size beginning at input iterator b2. Having this in mind it is straightforward
template <class InIter1, class InIter2>
bool my_equal(InIter1 b, InIter1 e, InIter2 b2) {
	while (b != e) {
		if (*b != *b2) return false;
		++b; ++b2;
	}
	return true;
}

template <class FIter1, class FIter2>
FIter1 my_search(FIter1 b, FIter1 e, FIter2 b2, FIter2 e2) {
	for (; b != e; ++b) {
		// simply reuse my_equal
		if (my_equal(b2, e2, b))
			return b;
	}
	return e;
}

template <class InIter1, class Type>
InIter1 my_find(InIter1 b, InIter1 e, const Type& t) {
	while (b != e) {
		if (*b == t) return b;
		b++;
	}

	return e;
}

template <class InIter1, class Pred>
InIter1 my_find_if(InIter1 b, InIter1 e, const Pred& p) {
	while (b != e) {
		if (p(*b)) return b;
		b++;
	}
	return e;
}

template <class InIter, class OuIter>
OuIter my_copy(InIter b, InIter e, OuIter d) {
	while (b != e) {
		*d++ = *b++;
	}
	return d;
}

template <class InIter, class OuIter, class Type>
OuIter my_remove_copy(InIter b, InIter e, OuIter d, const Type& t) {
	while (b != e) {
		if (*b != t) {
			*d++ = *b;
		}
		b++;
	}
	return d;
}

template <class InIter, class OuIter, class Pred>
OuIter my_remove_copy_if(InIter b, InIter e, OuIter d, Pred p) {
	while (b != e) {
		if (!p(*b)) {
			*d++ = *b;
		}
		b++;
	}
}

template <class FIter, class Type>
FIter my_remove(FIter b, FIter e, const Type& t) {
	FIter tmp = b;
	for (; b != e; ++b) {
		if (*b != t)
			*tmp++ = *b;
	}
	return tmp;
}

template <class InIter, class OuIter, class Fct>
OuIter my_transform(InIter e, InIter b, OuIter d, Fct f) {
	while (b != e) {
		*d++ = f(*b++);
	}
	return d;
}

template <class Type>
void my_swap(Type& a, Type& b) {
	Type c = a;
	a = b;
	b = c;
}

// Answer to Q8.4:
// We use a swap function to avoid using complexe notation. Indeed the subtle
// part is that we need to access the type of the value stored by the iterator.
// so we cannot write BiIter tmp = *first_fail; Hence we'd rather like to simplify
// things using a swaping function (that could be reuse by other fct as well).
template <class BiIter, class Pred>
BiIter my_partition(BiIter b, BiIter e, Pred p) {
	BiIter first_fail = b;
	for (; b != e; ++b) {
		if (p(*b)) {
			auto tmp = *first_fail;
			//typename std::iterator_traits<BiIter>::value_type tmp = *first_fail;
			*first_fail = *b;
			*b = tmp;
			first_fail++;
		}
	}
	return b;
}

// we don't have to change t so we either need to pass as a
// copy (we don't use &) or we need to pass t as a reference to a const
// and then we need to ensure to create another variable inside the fct
template <class InIter, class Type>
Type my_accumulate(InIter b, InIter e, Type t) {
	for (; b != e; ++b) {
		t += *b;
	}
	return t;
}

#endif // !_ALGO_

