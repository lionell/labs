#ifndef LOGGING_H_
#define LOGGING_H_

#include <iostream>

#include "utils.h"

#define LOG(x) Log("[" + std::to_string(proc::rank) + "]:\t" + x)
#define VLOG(x) VLog(#x, x)

namespace proc {
extern int rank;
}

template<typename T>
void Log(T x) {
	std::cout << x + "\n";
}

template<typename T>
void VLog(std::string s, T x) {
	VLog(s, std::to_string(x));
}

template<> inline // template specialization
void VLog(std::string s, std::string x) {
	LOG(s + "=" + x);
}

template<typename T>
void VLog(std::string s, T *a, int size) {
	VLog(s, Join(a, size));
}

#endif  // LOGGING_H_
