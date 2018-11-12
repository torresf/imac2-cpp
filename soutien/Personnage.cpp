#include "Personnage.hpp"
#include <iostream>

// Constructeurs
Personnage::Personnage():_vie(100),_degats(20){};
Personnage::Personnage(const int v, const int d):
	_vie(v),_degats(d){};

// Destructeur
Personnage::~Personnage(){};


void Personnage::quiSuisJe() const {
	std::cout << "Je suis un Personnage." << std::endl;
}

void Personnage::attaquer(Personnage &p) {
	p.setVie(p.getVie() - _degats);
}

void Personnage::getInfos() {
	this->quiSuisJe();
	std::cout << "Vie : " << getVie() << std::endl;
	std::cout << "Degats : " << getDegats() << std::endl;
}