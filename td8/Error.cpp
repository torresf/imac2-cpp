#include "Error.hpp"
#include <iostream>

// Constructeurs
Error::Error():_niveau(0), _code(0), _file(0), _line(0), _message(" ") 
{}

Error::Error(const int n, const int c, std::string f, int l, const char *m)
	:_niveau(n), _code(c), _file(f), _line(l)
{
	_message = "Exception lancée :\n"
				+ std::string("	Niveau : ") + std::to_string(_niveau) + '\n'
				+ "	Code : " + std::to_string(_code) + '\n'
				+ "	Fichier / ligne : " + std::string(_file) + ':' + std::to_string(_line) + '\n'
				+ "	Message : " + m;
}

// Destructeur
Error::~Error()
{}

const char* Error::what() const noexcept {
	return _message.c_str();
}