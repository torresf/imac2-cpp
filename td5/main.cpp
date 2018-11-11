#include "ImageRGBu8.hpp"
#include "ioPPM.hpp"
#include "Filter.hpp"
#include "Filters.hpp"
#include "Threshold.hpp"
#include "RemoveChannel.hpp"
#include "Mean.hpp"

int main(int argc, char const *argv[])
{

	/* ------- EX2 ------- */
	/*
	// read image
	ImageRGBu8 image1;
	readPPM(argv[1], image1);
	// apply filter and save
	Threshold t(100);
	t.applyFilter(image1);
	writePPM("test1.ppm", image1);
	*/


	/* ------- EX3 ------- */
	/*
	// load image
	ImageRGBu8 image2;
	readPPM(argv[1], image2);
	// apply filters
	Filters filters(2);
	Threshold t1(150);
	Threshold t2(100);
	filters.addFilter(t1);
	filters.addFilter(t2);
	filters.applyFilters(image2);
	// save image
	writePPM("test_ex3.ppm", image2);
	*/


	/* ------- EX4 ------- */
	/*
	// load image
	ImageRGBu8 image3;
	readPPM(argv[1], image3);
	// apply filters
	Filters filters(2);
	RemoveChannel rc1(2);
	RemoveChannel rc2(3);
	Threshold t(90);
	filters.addFilter(rc1);
	filters.addFilter(t);
	filters.addFilter(rc2);
	filters.applyFilters(image3);
	// save image
	writePPM("test_ex4.ppm", image3);
	*/


	/* ------- EX5 ------- */
	// load image
	ImageRGBu8 image4;
	readPPM(argv[1], image4);
	// apply filters
	Filters filters(2);
	Mean m1(2);
	filters.addFilter(m1);
	filters.applyFilters(image4);
	// save image
	writePPM("test_ex5.ppm", image4);

	return 0;
}