#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Veuillez entrer un entier" << std::endl;
	int n;
	std::cin >> n;

	if (n == 79)
	{
		std::cout << "Parfait" << std::endl;
	}
	if (n < 0) {
		std::cout << "Négatif" << std::endl;
	}
	if (n >= 0)
	{
		std::cerr << "Strictement positif" << std::endl;
	}
	return 0;
}