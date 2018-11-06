#include <iostream>
#include "Ellipse.hpp"
#include "Cercle.hpp"

Cercle::Cercle()
	:_radius(0)
{}

Cercle::Cercle(const double &r)
	:Ellipse(r, r)
{}

Cercle::~Cercle() 
{
	std::cout << "Destruction d'un Cercle" << std::endl;
}

void Cercle::quiSuisJe() const {
	std::cout << "Je suis un Cercle" << std::endl;
}