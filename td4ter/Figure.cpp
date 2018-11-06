#include <iostream>
#include "Figure.hpp"

Figure::Figure()
{}

Figure::~Figure() 
{
	std::cout << "Destruction d'une Figure" << std::endl;
}

void Figure::quiSuisJe() const {
	std::cout << "Je suis une Figure ..." << std::endl;
}