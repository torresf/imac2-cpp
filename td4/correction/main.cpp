#include <iostream>
#include <cstdlib>
#include <string>

#include "ImageRGBU8.hpp"
#include "ioPPM.hpp"

int main(int argc, char **argv) {

	// load arguments
	if(argc != 2){
		std::cerr << "usage: " << argv[0] << "image.ppm" << std::endl;
		return EXIT_FAILURE;
	}

	// load image
    ImageRGBU8 image;
	readPPM(argv[1], image);

	// do something
    image.toGreyScale();
    image.drawCircle();

	// save image
	writePPM("output.ppm", image);

	// default image (white)
	writePPM("default.ppm", ImageRGBU8(50,50));
	

	// other filters
    ImageRGBU8 image2;
	readPPM(argv[1], image2);
	image2.threshold(125);
	image2.removeChannel(1);
	image2.removeChannel(2);
	writePPM("red.ppm", image2);

	return(EXIT_SUCCESS);
}
