#ifndef __THRESHOLD__HPP
#define __THRESHOLD__HPP

#include "ImageRGBu8.hpp"
#include "Filter.hpp"

class Threshold : public Filter
{
	private:
		unsigned char _threshold;

	public:
		Threshold();
		Threshold(const int t);
		~Threshold();
		void applyFilter(ImageRGBu8 &ImageRGBU8);
};

#endif