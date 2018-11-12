#include "Personnage.hpp"
#include "Guerrier.hpp"
#include "Mage.hpp"

void presenter(Personnage &p) {
	p.getInfos();
}


int main(int argc, char const *argv[])
{
	Personnage p; // Classe mère
	// p.quiSuisJe();

	Mage m;
	// m.quiSuisJe();

	Guerrier g;
	// g.quiSuisJe();

	presenter(m);

	p.attaquer(m);
	
	presenter(m);
	return 0;
}