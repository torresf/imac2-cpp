#include "Mage.hpp"
#include <iostream>

// Constructeurs
Mage::Mage():_mana(30){};

// Destructeur
Mage::~Mage(){};


void Mage::quiSuisJe() const {
	std::cout << "Je suis un Mage." << std::endl;
}

void Mage::getInfos() {
	Personnage::getInfos();
	std::cout << "Mana : " << getMana() << std::endl;
}