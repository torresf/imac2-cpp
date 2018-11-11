#ifndef __MEAN__HPP
#define __MEAN__HPP

#include "ImageRGBu8.hpp"
#include "Filter.hpp"

class Mean : public Filter
{
	private:
		int _kernelSize;

	public:
		Mean();
		Mean(const int k);
		~Mean();
		void applyFilter(ImageRGBu8 &image);
};

#endif