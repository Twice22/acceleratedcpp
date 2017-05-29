#ifndef _STR_H_
#define _STR_H_

#include <string>
#include <memory>
#include <iterator>


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
	char& operator[](size_type i) { return data[i]; };
	const char& operator[](size_type i) const { return data[i]; };

	// size()
	size_type size() const { return len - 1; }

	// begin() and end()
	iterator begin() { return data; };
	const_iterator begin() const { return data; };
	iterator end() { return data + len - 1; }
	const_iterator end() const { return data + len - 1; };

	// operator +=
	Str& operator+=(const Str&);

	// using array structure to define Str
private:
	iterator data;
	size_type len;

	std::allocator<char> alloc;

	void create(size_type, char);
	template <class In> void create(In, In);

	void uncreate();
};

// >> operator
std::ostream& operator<<(std::ostream&, const Str&);


// private function
template <class In>
void Str::create(In b, In e) {
	len = e - b + 1;
	data = alloc.allocate(len);
	std::uninitialized_copy(b, e, data);
	alloc.construct(data + len - 1, '\0');
}

#endif // !_STR_H_
