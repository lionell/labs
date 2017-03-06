#include "logging.h"
#include <gflags/gflags.h>

DECLARE_bool(verbose);

std::string DefaultDecorator(std::string s) {
	return s;
}

std::function<std::string(std::string)> DECORATOR = DefaultDecorator;

void RegisterDecorator(std::function<std::string(std::string)> decorator) {
	DECORATOR = decorator;
}

void Log(std::string s) {
	if (FLAGS_verbose) Print(DECORATOR(s));
}

void Print(std::string s) {
	std::cerr << s + "\n";
}
