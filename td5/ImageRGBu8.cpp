#include "ImageRGBu8.hpp"
#include <algorithm>

// Constructeurs
ImageRGBu8::ImageRGBu8() 
	:_width(0), _height(0), _data() {
}

ImageRGBu8::ImageRGBu8(const ImageRGBu8 &image) 
	:_width(image._width), _height(image._height), _data(image._data) {
}

ImageRGBu8::ImageRGBu8(const unsigned int width, const unsigned int height)
	:_width(width), _height(height), _data(width*height*3) {
	std::fill(_data.begin(), _data.end(), 255);
}

ImageRGBu8::ImageRGBu8(const unsigned int width, const unsigned int height, const std::vector<unsigned char> &data)
	:_width(width), _height(height), _data(data) {
}


// Destructeur
ImageRGBu8::~ImageRGBu8() {}

void ImageRGBu8::greyscale() {
	float moy;
	for (unsigned int i = 0; i < _width * _height * 3; i+=3)
	{
		moy = (_data[i] +_data[i+1] +_data[i+2]) / 3;
		_data[i] = _data[i+1] = _data[i+2] = moy;
	}
}

// void ImageRGBu8::circle(const unsigned char r = 255, const unsigned char g = 0, const unsigned char b = 0) {
// 	float moy;
// 	for (unsigned int i = 0; i < _width * _height * 3; i+=3)
// 	{
// 		moy = (_data[i] +_data[i+1] +_data[i+2]) / 3;
// 		_data[i] = _data[i+1] = _data[i+2] = moy;
// 	}
// }