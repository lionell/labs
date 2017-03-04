#ifndef UTILS_H_
#define UTILS_H_

#include <sstream>

template<typename T>
T *ExtendArray(T a[], int size, int new_size) {
	T *temp = new T[new_size];
	memcpy(temp, a, size * sizeof(T));
	delete[] a;
	return temp;
}

template<typename T>
std::string Join(T *a, int size) {
	std::stringstream ss;
	ss << "[";
	for (int i = 0; i < size - 1; i++) {
		ss << a[i] << ", ";
	}
	ss << a[size - 1] << "]";
	return ss.str();
}

#endif  // UTILS_H_
