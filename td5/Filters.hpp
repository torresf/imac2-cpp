#ifndef __FILTERS__HPP
#define __FILTERS__HPP

#include "ImageRGBu8.hpp"
#include "Filter.hpp"

class Filters
{
	private:
		unsigned int _size;
		unsigned int _nbFilters;
		Filter* *_filters;

	public:
		Filters(); // Constructeur
		Filters(const int n); // Constructeur
		~Filters(); // Destructeur

		void addFilter(Filter &filter); // Ajoute un filtre
		void applyFilters(ImageRGBu8 &image); // Applique le filtre
};

#endif
