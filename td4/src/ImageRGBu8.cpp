#include "../include/ImageRGBu8.hpp"
#include <algorithm>

// Constructeurs
ImageRGBU8::ImageRGBU8() 
	:_width(0), _height(0), _data() {
}

ImageRGBU8::ImageRGBU8(const ImageRGBU8 &image) 
	:_width(image._width), _height(image._height), _data(image._data) {
}

ImageRGBU8::ImageRGBU8(const unsigned int width, const unsigned int height)
	:_width(width), _height(height), _data(width*height*3) {
	std::fill(_data.begin(), _data.end(), 255);
}

ImageRGBU8::ImageRGBU8(const unsigned int width, const unsigned int height, const std::vector<unsigned char> &data)
	:_width(width), _height(height), _data(data) {
}


// Destructeur
ImageRGBU8::~ImageRGBU8() {}
