#include "Filters.hpp"
#include "Filter.hpp"
#include <iostream>

// Constructeurs
// Filters::Filters() {
// 	_size = 0;
// 	_nbFilters = 0;
// 	_filters = new Filter*[0];
// }


Filters::Filters(const int n) {
	_size = n;
	_nbFilters = 0;
	_filters = new Filter*[n];
}

// Destructeur
Filters::~Filters() {
	delete[] _filters;
}


// Méthodes sur les filtres

// Ajout d'un filtre : On ajoute le nouveau filtre au tableau _filters, puis on incrémente _nbFilters
void Filters::addFilter(Filter &filter) {
	_filters[_nbFilters] = &filter;
	_nbFilters++;
}

void Filters::applyFilters(ImageRGBu8 &image) {
	for (unsigned int i = 0; i < _nbFilters; ++i)
	{	
		_filters[i]->applyFilter(image);
	}
}