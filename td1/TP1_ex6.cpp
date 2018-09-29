// ================================
// POO C++ - IMAC 2
// TP 1 - Exercice 5
// ================================

#include <iostream>
#include <vector>
#include "chrono.hpp"

namespace TP_CPP_IMAC2
{
	float mean(std::vector<int> &v) {
		float moyenne;
		for (int i = 0; i < v.size(); ++i)
		{
			moyenne += v[i];
		}
		moyenne = moyenne / v.size();
		return moyenne;
	}

	float meanCopy(std::vector<int> v) {
		float moyenne;
		for (int i = 0; i < v.size(); ++i)
		{
			moyenne += v[i];
		}
		moyenne = moyenne / v.size();
		return moyenne;
	}

	int main(int argc, char *argv[])
	{
		std::vector<int> v;
		std::cout << "Entrez la taille du vecteur :" << std::endl;
		int taille;
		std::cin >> taille;

		for (int i = 0; i < taille; ++i)
		{
			v.push_back(i%10);
		}

		std::cout << "Taille du vecteur : " << v.size() << std::endl;

		for (int i = 0; i < 3; ++i)
		{
			std::cout << "Adresse : " << &v[i] << std::endl;
			std::cout << "Taille : " << sizeof(v[i]) << std::endl;
		}

		Chrono chrono;
		chrono.start();
		std::cout << "Moyenne du vecteur (mean) : " << mean(v) << std::endl;
		chrono.stop();
		std::cout << "Time : " << chrono.timeSpan() << " s" << std::endl;

		chrono.start();
		std::cout << "Moyenne du vecteur (meanCopy) : " << mean(v) << std::endl;
		chrono.stop();
		std::cout << "Time : " << chrono.timeSpan() << " s" << std::endl;

		v.pop_back();
		std::cout << "Pop back : Taille du vecteur : " << v.size() << std::endl;

		v.clear();
		std::cout << "Clear : Taille du vecteur : " << v.size() << std::endl;

		return 0;
	}
}

// Fonction main classique, point d'entr�e du programme
int main(int argc, char *argv[])
{
	// Appel de la fonction main de l'espace de nom TP_CPP_IMAC2
	return TP_CPP_IMAC2::main(argc, argv);
}

