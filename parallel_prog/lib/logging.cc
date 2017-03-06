#include "logging.h"

std::string DefaultDecorator(std::string s) {
	return s;
}

std::function<std::string(std::string)> DECORATOR = DefaultDecorator;

void RegisterDecorator(std::function<std::string(std::string)> decorator) {
	DECORATOR = decorator;
}

void Log(std::string x) {
	std::cerr << DECORATOR(x) + "\n";
}
