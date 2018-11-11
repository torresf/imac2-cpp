#ifndef __REMOVE_CHANNEL__HPP
#define __REMOVE_CHANNEL__HPP

#include "ImageRGBu8.hpp"
#include "Filter.hpp"

class RemoveChannel : public Filter
{
	private:
		unsigned int _channel; // 0: red, 1: green, 2: blue

	public:
		RemoveChannel();
		RemoveChannel(const unsigned int c);
		~RemoveChannel();
		void applyFilter(ImageRGBu8 &ImageRGBU8);
};

#endif