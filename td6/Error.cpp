#include "Error.hpp"
#include "iostream"

// Constructeur
Error::Error():_niveau(0), _code(0), _message(" ") {}
Error::Error(const int n, const int c, const char* m):_niveau(n), _code(c), _message(m) {}

// Destructeur
Error::~Error(){}

const char* Error::what() const noexcept {
	return _message.c_str();
}