#include <iostream>
#include <vector>
#include <algorithm>
#include "Figure.hpp"
#include "Rectangle.hpp"
#include "Carre.hpp"
#include "Ellipse.hpp"
#include "Cercle.hpp"

void afficher(Figure *f) {
	f->quiSuisJe();
}

int main(int argc, char const *argv[])
{
	/*
	Rectangle r1(2.6, 4.42), r2;
	std::cout << r1.surface() << std::endl;
	r1.setLargeur(3.9);

	Carre c1(3.8), c2;
	std::cout << c1.surface() << std::endl;
	c2.setCote(2.9);

	r1.quiSuisJe();
	c1.quiSuisJe();
	*/
	
	// ---- Exercice 7 ----
	// Figure f;
	// f.quiSuisJe();

	// ---- Exercice 8 ----
	// Rectangle r1;
	// Rectangle r2 = Carre (8); // OK
	// Rectangle r2 = Cercle (8); // Erreur
	// Carre r2 = r1; // Erreur

	// ---- Exercice 9 ----
	// Rectangle *r = new Rectangle(1,8);
	// afficher(r);
	// Ellipse *e = new Ellipse(11,1);
	// afficher(e);

	// ---- Exercice 10 ----
	std::vector<Figure*> listFig;
	listFig.push_back(new Rectangle(1,8));
	listFig.push_back(new Ellipse(1, 2));
	listFig.push_back(new Carre(5));
	listFig.push_back(new Cercle());

	std::for_each(listFig.begin(), listFig.end(),
		[](Figure *figure)
		{
			afficher(figure);
			std::cout << figure->surface() << std::endl;
		}
	);

	return 0;
}
