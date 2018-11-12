#include "Guerrier.hpp"
#include <iostream>

// Constructeurs
Guerrier::Guerrier(){};
// Destructeur
Guerrier::~Guerrier(){};

void Guerrier::quiSuisJe() const {
	std::cout << "Je suis un Guerrier." << std::endl;
}
