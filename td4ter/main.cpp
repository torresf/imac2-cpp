#include <iostream>
#include "Rectangle.hpp"
#include "Carre.hpp"

int main(int argc, char const *argv[])
{
	Rectangle r1(2.6, 4.42), r2;
	std::cout << r1.surface() << std::endl;
	r1.setLargeur(3.9);

	Carre c1(3.8), c2;
	std::cout << c1.surface() << std::endl;
	c2.setCote(2.9);


	std::cout << r1.quiSuisJe() << std::endl;
	std::cout << c1.quiSuisJe() << std::endl;
	return 0;
}