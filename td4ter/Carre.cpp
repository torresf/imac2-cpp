#include <iostream>
#include "Rectangle.hpp"
#include "Carre.hpp"

Carre::Carre()
	:_cote(0)
{}

Carre::Carre(const double &c)
	:Rectangle(c, c) 
{}

Carre::~Carre() 
{
	std::cout << "Destruction d'un Carré" << std::endl;
}

std::string Carre::quiSuisJe() const {
	return "Je suis un carré";
}