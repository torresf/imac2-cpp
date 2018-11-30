#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <functional>
#include "Majuscule.hpp"
#include "AjoutSiPair.hpp"

template <class T>
void display(T deb, T fin) {
	for (T i = deb; i != fin; i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{

	/* ----- EXO 1 ----- */ 
	/*
	std::vector<int> v;
	
	if (v.empty())
		std::cout << "Le vecteur est vide" << std::endl;

	std::cout << "Taille du vecteur : " << v.size() << std::endl;
	std::cout << "Taille maximale d'un vecteur d'entier : " << v.max_size() << std::endl;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::cout << "Nouvelle taille : " << v.size() << std::endl;
	std::cout << "Contenu du vecteur : " << std::endl;

	for (unsigned int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	*/


	/* ----- EXO 2 ----- */ 
	/* 
	std::vector<std::string> v1, v2;
	v1.push_back("Test");
	v2.push_back("Swap");
	std::cout << "v1 : " << v1[0] << std::endl;
	std::cout << "v2 : " << v2[0] << std::endl;
	std::cout << "---- SWAP ----" << std::endl;
	v1.swap(v2);
	std::cout << "v1 : " << v1[0] << std::endl;
	std::cout << "v2 : " << v2[0] << std::endl;
	*/


	/* ----- EXO 3 ----- */ 
	/*
	std::vector<int> v;
	for (unsigned int i = 0; i < 30; ++i)
		v.push_back(rand() % 21);
	display(v.begin(), v.end());
	std::sort(v.begin(), v.end());
	display(v.begin(), v.end());

	int countSeven = std::count(v.begin(), v.end(), 7);
	std::cout << "Nombre de 7 dans v : " << countSeven << std::endl;
	*/


	/* ----- EXO 4 ----- */ 
	/*
	std::deque<int> d(5);
	for (unsigned int i = 0; i < d.size(); ++i)
		d[i] = rand();

	display(d.begin(), d.end());

	for (unsigned int i = 0; i < d.size(); ++i) {
		d.push_front(rand());
		d.pop_back();
		display(d.begin(), d.end());
	}
	*/


	/* ----- EXO 5 ----- */ 
	/* 
	std::list<std::string> l_philo {"Platon", "Aristote", "Descartes", "Kant"};
	std::list<std::string> l_math {"Gauss", "Laplace", "Poincaré", "Descartes"};
	l_philo.sort();
	l_math.sort();

	display(l_philo.begin(), l_philo.end());
	display(l_math.begin(), l_math.end());

	std::list<std::string> l_all;
	std::merge(l_philo.begin(), l_philo.end(), l_math.begin(), l_math.end(), std::back_inserter(l_all));

	l_all.unique();
	l_all.reverse();

	display(l_all.begin(), l_all.end());
	*/


	/* ----- EXO 6 ----- */ 
	/*
	std::map<std::string, int> m;
	m.insert(std::make_pair("Bobby", 22));
	m.insert(std::make_pair("Flo", 21));
	m.insert(std::make_pair("Tom", 20));
	// m.insert(std::make_pair("Marie", 32));

	std::map<std::string, int>::iterator it = m.begin();
	while(it != m.end())
	{
		std::cout << it->first << " a " << it->second << " ans." << std::endl;
		it++;
	}

	it = m.find("Marie");
	if (it != m.end())
		std::cout << it->first << " a " << it->second << " ans." << std::endl;
	else
		std::cerr << "L'âge de 'Marie' n'existe pas." << std::endl;
	*/


	/* ----- EXO 7 ----- */
	
	std::vector<char> v{'a', 'b', 'c'};
	display(v.begin(), v.end());
	std::vector<char>::iterator it;

	// Majuscule toMaj;
	// for (it = v.begin(); it != v.end(); ++it)
	// 	*it = toMaj(*it);

	std::function<char(char&)> foncteur;
	foncteur = [](char &l) {
		return toupper(l);
	};

	std::for_each(v.begin(), v.end(), foncteur);
	for (it = v.begin(); it != v.end(); ++it)
		*it = foncteur(*it);

	display(v.begin(), v.end());
	

	/* ----- EXO 8 ----- */

	// std::list<int> l {1, 2, 3, 4, 5, 6};
	// display(l.begin(), l.end());
	// std::list<int>::iterator it;

	// /* Version Foncteur */
	// AjoutSiPair ajout;
	// for (it = l.begin(); it != l.end(); ++it)
	// 	*it = ajout(*it);

	// /* Affichage du résultat */
	// display(l.begin(), l.end());

	// /* Version Fonction Lambda */
	// std::function<int(const int)> foncteur;
	// foncteur = [](const int n) {
	// 	return (n%2 == 0) ? n+10 : n;
	// };
	// for (it = l.begin(); it != l.end(); ++it)
	// 	*it = foncteur(*it);

	// /* Affichage du résultat */
	// display(l.begin(), l.end());


	return 0;
}