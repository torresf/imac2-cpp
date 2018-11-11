#include "Threshold.hpp"
#include <iostream>

// Constructeurs
Threshold::Threshold():_threshold(175) {}
Threshold::Threshold(const int t):_threshold(t) {}

// Destructeur
Threshold::~Threshold() {}

// Méthodes 
void Threshold::applyFilter(ImageRGBu8 &ImageRGBU8) {
	std::cout << "applyFilter Threshold" << std::endl;
	float moy;
	for (unsigned int i = 0; i < ImageRGBU8.width() * ImageRGBU8.height() * 3; i+=3)
	{
		moy = (ImageRGBU8.data()[i] + ImageRGBU8.data()[i+1] +ImageRGBU8.data()[i+2]) / 3;
		if (moy < _threshold) {
			ImageRGBU8.data()[i] = 0;
			ImageRGBU8.data()[i+1] = 0;
			ImageRGBU8.data()[i+2] = 0;
		} else {
			ImageRGBU8.data()[i] = 255;
			ImageRGBU8.data()[i+1] = 255;
			ImageRGBU8.data()[i+2] = 255;
		}
	}
}