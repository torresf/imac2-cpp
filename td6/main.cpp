#include <iostream>
#include "Error.hpp"

int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 0;

	std::cout << "a/2 = " << a/2 << std::endl;

	try {
		if (b == 0)
		{
			throw Error(1, 2, std::string(__FILE__), __LINE__, "Dénominateur nul");
		}
		else 
		{
			std::cout << "a/b = " << a/b << std::endl;
		}
	}
	catch (Error &e) {
		std::cerr << e.what() << std::endl;
		/*
		std::cerr << "Exception lancée : " << std::endl;
		std::cerr << "	Niveau : " << e.getNiveau() << std::endl;
		std::cerr << "	Code : " << e.getCode() << std::endl;
		std::cerr << "	File : " << e.getFile() << std::endl;
		std::cerr << "	Line : " << e.getLine() << std::endl;
		std::cerr << "	Exception lancée : " << e.what() <<  std::endl;
		*/
	}

	std::cout << "a/5 = " << a/5 << std::endl;
	std::cout << "Terminé ! " << std::endl;
	
	return 0;
}