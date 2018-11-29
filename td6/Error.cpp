#include "Error.hpp"
#include "iostream"

// Constructeurs
Error::Error():_niveau(0), _code(0), _message(" ") 
{}

Error::Error(const int n, const int c, std::string f, int l, const char *m)
	:_niveau(n), _code(c), _file(f), _line(l), _message(m) 
{}

// Destructeur
Error::~Error()
{}

const char* Error::what() const noexcept {
	std::string message = "";
	message.append("	Niveau : ");
	return message.c_str();
}