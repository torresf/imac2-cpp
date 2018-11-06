#ifndef __ImageRGBu8__HPP
#define __ImageRGBu8__HPP

#include <vector>

class ImageRGBu8
{
	public:
		// Constructeurs
		ImageRGBu8();
		ImageRGBu8(const ImageRGBu8 &image);
		ImageRGBu8(const unsigned int width, const unsigned int height);
		ImageRGBu8(const unsigned int width, const unsigned int height, const std::vector<unsigned char> &data);

		// Destructeur
		~ImageRGBu8();

		// Méthodes
		inline const unsigned char &operator() (const unsigned int x, const unsigned int y, const unsigned int c) const {
			return _data[(y*_width+x)*3 + c];
		}

		inline unsigned char &operator() (const unsigned int x, const unsigned int y, const unsigned int c) {
			return _data[(y*_width+x)*3 + c];
		}

		inline unsigned char* data() {
			return _data.data();
		}

		inline const unsigned char* data() const {
			return _data.data();
		}

		inline unsigned int width() const {
			return _width;
		}

		inline unsigned int height() const {
			return _height;
		}

		void greyscale();
		// void circle(const unsigned char r = 255, const unsigned char g = 0, const unsigned char b = 0);

	private:
		// Attributs
		unsigned int _width;
		unsigned int _height;
		std::vector<unsigned char> _data;
};

#endif