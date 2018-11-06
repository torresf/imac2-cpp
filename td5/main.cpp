#include "ImageRGBu8.hpp"
#include "ioPPM.hpp"
#include "Filter.hpp"
#include "Threshold.hpp"

int main(int argc, char const *argv[])
{
	// read image
	ImageRGBu8 image1;
	readPPM(argv[1], image1);
	// apply filter and save
	Threshold t(100);
	t.applyFilter(image1);
	writePPM("test1.ppm", image1);

	return 0;
}