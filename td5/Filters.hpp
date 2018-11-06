#ifndef __FILTERS__HPP
#define __FILTERS__HPP

#include "ImageRGBu8.hpp"

class Filters
{
	private:
		unsigned int _filters;
		unsigned int _nbFilters;
		Filter* _filters;
	public:
		Filters();
		~Filters();
};

#endif