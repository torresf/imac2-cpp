#ifndef __SOBEL__HPP
#define __SOBEL__HPP

#include "ImageRGBu8.hpp"
#include "Filter.hpp"

class Sobel : public Filter
{
	private:
		int _kernelSize;

	public:
		Sobel();
		~Sobel();
		void applyFilter(ImageRGBu8 &image);
};

#endif