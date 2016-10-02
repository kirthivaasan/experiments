#include <functional> // for std::hash
#include "bloom.h"

namespace kirthi {

template <class T>
bloom<T>::bloom(int reserve_size) : num_elements(0) {
	capacity = 4 * reserve_size;
	bit_array.reserve(capacity);
}

template <class T>
size_t bloom<T>::regularHash(const T& obj) {
	size_t hash = std::hash<T>()(obj); // regular std hash
	return hash % capacity;
}

template <class T>
size_t bloom<T>::knuthHash(const T& obj) {
	size_t hash = std::hash<T>()(obj);
	hash = hash * 2654435761;
	return hash % capacity;
}

template <class T>
void bloom<T>::add(const T& obj) {
	num_elements++;
	bit_array[regularHash(obj)] = true;
	bit_array[knuthHash(obj)] = true;
}

template <class T>
bool bloom<T>::contains(const T& obj) {
	return bit_array[regularHash(obj)] && bit_array[knuthHash(obj)];
}

template <class T>
bloom<T>::~bloom() {
	//nothing yet
}

} // end kirthi namespace