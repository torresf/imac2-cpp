#include <iostream>
#include "Ellipse.hpp"

Ellipse::Ellipse()
	:_radiusX(0), _radiusY(0)
{}

Ellipse::Ellipse(const double &rx, const double &ry)
	:_radiusX(rx), _radiusY(ry)
{}

Ellipse::~Ellipse() 
{
	std::cout << "Destruction d'une ellipse" << std::endl;
}

void Ellipse::quiSuisJe() const {
	std::cout << "Je suis une Ellipse" << std::endl;
}