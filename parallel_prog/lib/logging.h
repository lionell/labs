#ifndef LOGGING_H_
#define LOGGING_H_

#include <iostream>
#include <functional>

#include "utils.h"

#define VLOG(x) VLog(#x, x)

void RegisterDecorator(std::function<std::string(std::string)> decorator);
void Log(std::string s);
void Print(std::string s);

template<typename T>
void VLog(std::string s, T x) {
	VLog(s, ToString(x));
}

template<> inline // template specialization
void VLog(std::string s, std::string x) {
	Log(s + "=" + x);
}

template<typename T>
void VLog(std::string s, T *a, int size) {
	VLog(s, Join(a, size));
}

template<typename T>
void VPrint(std::string s, T x) {
	VPrint(s, ToString(x));
}

template<> inline // template specialization
void VPrint(std::string s, std::string x) {
	Print(s + "=" + x);
}

template<typename T>
void VPrint(std::string s, T *a, int size) {
	VPrint(s, Join(a, size));
}

template<typename T>
void Print(T *a, int size) {
	Print(Join(a, size));
}

#endif  // LOGGING_H_
