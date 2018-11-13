#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>

void displayVector(const std::vector<int> &v) {
	for (unsigned int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void displayDeque(const std::deque<int> &d) {
	for (unsigned int i = 0; i < d.size(); ++i)
		std::cout << d[i] << " ";
	std::cout << std::endl;
}

void displayList(const std::list<std::string> &l) {
	for (auto item : l)
	    std::cout << item << " ";
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
	displayVector(v);
	std::sort(v.begin(), v.end());
	displayVector(v);

	int countSeven = std::count(v.begin(), v.end(), 7);
	std::cout << "Nombre de 7 dans v : " << countSeven << std::endl;
	*/


	/* ----- EXO 4 ----- */ 
	/*
	std::deque<int> d(5);
	for (unsigned int i = 0; i < d.size(); ++i)
		d[i] = rand();

	displayDeque(d);

	for (unsigned int i = 0; i < d.size(); ++i) {
		d.push_front(rand());
		d.pop_back();
		displayDeque(d);
	}
	*/


	/* ----- EXO 5 ----- */ 
	std::list<std::string> l_philo {"Platon", "Aristote", "Descartes", "Kant"};
	std::list<std::string> l_math {"Gauss", "Laplace", "Poincaré", "Descartes"};
	l_philo.sort();
	l_math.sort();

	displayList(l_philo);
	displayList(l_math);

	std::list<std::string> l_all;
	l_philo.merge(l_math);
	
	l_all = l_philo;
	l_all.unique();
	l_all.reverse();

	displayList(l_all);
	return 0;
}