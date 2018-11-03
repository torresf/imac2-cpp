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

std::string Rectangle::quiSuisJe() const {
	return "Je suis un rectangle";
}