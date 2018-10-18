#include <iostream>
#include <algorithm>
#include "../include/VectorD.hpp"

int main(int argc, char const *argv[])
{
	int n = 3;
	VectorD v(n); // Constructeur classique 
	VectorD u(v); // Constructeur par copie

	std::cout << "Taille de u : " << v.size() << std::endl;
	std::cout << "Taille de v : " << u.size() << std::endl;

	// std::cout << "--- u.setSize(6) ---" << std::endl;
	// std::cout << "--- v.setSize(6) ---" << std::endl;
	// u.setSize(6);
	// v.setSize(6);
	// std::cout << "Nouvelle taille de u : " << u.size() << std::endl;
	// std::cout << "Nouvelle taille de v : " << v.size() << std::endl;

	v.setValue(0, 1);
	v.setValue(1, 2);
	v.setValue(2, 3);

	for (int i = 0; i < n; ++i)
	{
		v.setValue(i, i);
		u.setValue(i, n-i);
	}

	for (int i = 0; i < n; ++i)
	{
		std::cout << v.getValue(i) << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < n; ++i)
	{
		std::cout << u.getValue(i) << " ";
	}
	std::cout << std::endl;

	// v.normalize();

	VectorD w = u + v; // Test operator+


	for (int i = 0; i < n; ++i)
	{
		std::cout << w.getValue(i) << " ";
	}

	std::cout << std::endl;

	w.save("sortie.txt");
	return 0;
}