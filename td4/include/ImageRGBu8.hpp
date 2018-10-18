#include <vector>

class ImageRGBU8
{
	public:
		// Constructeurs
		ImageRGBU8();
		ImageRGBU8(const ImageRGBU8 &image);
		ImageRGBU8(const unsigned int width, const unsigned int height);
		ImageRGBU8(const unsigned int width, const unsigned int height, const std::vector<unsigned char> &data);

		// Destructeur
		~ImageRGBU8();

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



	private:
		// Attributs
		unsigned int _width;
		unsigned int _height;
		std::vector<unsigned char> _data;
};
