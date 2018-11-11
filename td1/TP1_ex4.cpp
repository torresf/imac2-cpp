#include <iostream>

int maxValue(int *tab, int taille) {
	int max = 0;

	for (int i = 0; i < taille; ++i)
	{
		if (tab[i] > max)
		{
			max = tab[i];
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	std::cout << "Nombre d'éléments dans le tableau :" << std::endl;
	int taille;
	std::cin >> taille;
	int *tab = new int[taille];

	for (int i = 0; i < taille; ++i)
	{
		std::cout << "Entrez un entier :" << std::endl;
		std::cin >> tab[i];
	}

	std::cout << "3 premiers entiers" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "Adresse : " << &tab[i] << std::endl;
		std::cout << "Taille : " << sizeof(tab[i]) << std::endl;
	}

	std::cout << "Premier élément : " << *tab << std::endl;
	std::cout << "5ème élément : " << *(tab+4) << std::endl;

	std::cout << "maxValue : " << maxValue(tab, taille) << std::endl;

	delete(tab);
	return 0;
}
