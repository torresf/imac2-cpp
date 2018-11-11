#include "RemoveChannel.hpp"
#include <iostream>

// Constructeurs
RemoveChannel::RemoveChannel():_channel(0) {}
RemoveChannel::RemoveChannel(const unsigned int c):_channel(c) {}

// Destructeur
RemoveChannel::~RemoveChannel() {}

// Méthodes 
void RemoveChannel::applyFilter(ImageRGBu8 &ImageRGBU8) {
	std::cout << "applyFilter RemoveChannel" << std::endl;
	for (unsigned int i = 0; i < ImageRGBU8.width() * ImageRGBU8.height() * 3; i+=3)
		ImageRGBU8.data()[i + _channel] = 0;
}