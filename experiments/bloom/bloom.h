#ifndef bloom_h
#define bloom_h

#include <vector>

typedef std::size_t size_t;

namespace kirthi {

template <class T>
class bloom {
private:
	std::vector<bool> bit_array;
	int num_elements;
	int capacity;
	size_t regularHash(const T& obj);
	size_t knuthHash(const T& obj);
public:
	bloom(int reserve_size); // if storing n elements reserved_size sdefaults to 4n
	~bloom();
	void add(const T& obj);
	bool contains(const T& obj);
	int size() { return num_elements; }
};

} // end namespace 
#include "bloom.cpp"

#endif