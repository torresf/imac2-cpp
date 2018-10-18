#include "ImageRGBu8.hpp"
#include "ioPPM.hpp"

int main(int argc, char const *argv[])
{
	ImageRGBu8 image;
	readPPM("image.ppm", image);

	image(50, 50, 1) = image(50, 50, 2) = 0;
	image(50, 50, 0) = 255;

	image.greyscale();
	image.circle();

	writePPM("output.ppm", image);

	return 0;
}