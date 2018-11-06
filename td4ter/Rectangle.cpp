#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle()
	:_largeur(0), _hauteur(0)
{}

Rectangle::Rectangle(const double &l, const double &h)
	:_largeur(l), _hauteur(h)
{}

Rectangle::~Rectangle() 
{
	std::cout << "Destruction d'un Rectangle" << std::endl;
}

void Rectangle::quiSuisJe() const {
	std::cout << "Je suis un Rectangle" << std::endl;
}