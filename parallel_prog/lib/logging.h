#ifndef LOGGING_H_
#define LOGGING_H_

#include <iostream>
#include <functional>

#include "utils.h"

#define VLOG(x) VLog(#x, x)

void RegisterDecorator(std::function<std::string(std::string)> decorator);
void Log(std::string x);

template<typename T>
void VLog(std::string s, T x) {
	VLog(s, std::to_string(x));
}

template<> inline // template specialization
void VLog(std::string s, std::string x) {
	Log(s + "=" + x);
}

template<typename T>
void VLog(std::string s, T *a, int size) {
	VLog(s, Join(a, size));
}

#endif  // LOGGING_H_
