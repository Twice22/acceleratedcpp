#ifndef _STR_H_
#define _STR_H_

#include <string>
#include <memory>
#include <iterator>
#include <cstring>
#include <iostream> // Answer to Q12.9


class Str {
	// to access private member
	friend std::istream& operator>>(std::istream&, Str&);
public:
	// create synonyms to access data structure
	typedef char* iterator;
	typedef const char* const_iterator;
	typedef size_t size_type;

	// Constructor. Create array with null-terminated char
	// we will use a private fct call create to handle the creation
	Str() { create(0, '\0'); }
	Str(size_type n, char c) { create(n, c); };
	Str(const Str& s) { create(s.begin(), s.end()); }; // need to create begin(), end()
	template <class In> Str(In b, In e) { create(b, e); };
	Str(const char* s) { create(s, s + std::strlen(s)); };

	Str& operator=(const Str& s) { // assignment
		if (this != &s) {
			uncreate();
			create(s.begin(), s.end());
		}
		return *this;
	}

	// destructor
	~Str() { uncreate(); };

	// []
	char& operator[](size_type i) { return cdata[i]; };
	const char& operator[](size_type i) const { return cdata[i]; };

	// size()
	size_type size() const { return len - 1; }

	// begin() and end()
	iterator begin() { return cdata; };
	const_iterator begin() const { return cdata; };
	iterator end() { return cdata + len - 1; }
	const_iterator end() const { return cdata + len - 1; };

	// operator +=
	Str& operator+=(const Str&);

	const char* c_str() const { return cdata; };
	const char* data() const { return cdata; };
	size_type copy(iterator, size_type, size_type = 0) const;

	bool operator==(Str& rhs) const {
		return strcmp(cdata, rhs.c_str()) == 0;
	}

	bool operator>=(Str& rhs) const {
		return strcmp(cdata, rhs.c_str()) >= 0;
	}

	bool operator>(Str& rhs) const {
		return strcmp(cdata, rhs.c_str()) > 0;
	}

	bool operator<=(Str& rhs) const {
		return strcmp(cdata, rhs.c_str()) <= 0;
	}

	bool operator<(Str& rhs) const {
		return strcmp(cdata, rhs.c_str()) < 0;
	}

	bool operator!=(Str& rhs) const {
		return strcmp(cdata, rhs.c_str()) != 0;
	}

	operator bool() const { return size() > 0; };

	// using array structure to define Str
private:
	iterator cdata;
	size_type len;

	std::allocator<char> alloc;

	void create(size_type, char);
	template <class In> void create(In, In);

	void uncreate();
};

// << operator
std::ostream& operator<<(std::ostream&, const Str&);


// private function
template <class In>
void Str::create(In b, In e) {
	len = e - b + 1;
	cdata = alloc.allocate(len);
	std::uninitialized_copy(b, e, cdata);
	alloc.construct(cdata + len - 1, '\0');
}

Str operator+(const Str& lhs, const Str& rhs);
Str operator+(const char* lhs, const Str& rhs);
Str operator+(const Str& lhs, const char* rhs);

std::istream& getline(std::istream&, Str&, char = '\n');

// Answer to Q12.9
std::ostream_iterator<char>& operator<<(std::ostream_iterator<char>&, const Str&);

#endif // !_STR_H_
