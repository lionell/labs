#ifndef LOG_H_
#define LOG_H_

#include <iostream>
#include "vars.h"

#define VLOG(x) VLog(#x, x)
#define LOG(x) Log("[" + std::to_string(proc::rank) + "]:\t" + x)

void Log(std::string s) {
	std::cout << s << std::endl;
}

template<typename T>
void VLog(std::string s, T x) {
	VLog(s, std::to_string(x));
}

template<>
void VLog(std::string s, std::string x) {
	LOG(s + "=" + x);
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

#endif
