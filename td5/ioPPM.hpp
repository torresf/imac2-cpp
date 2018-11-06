#include <iostream>
#include <string>
#include <fstream>

#include "ImageRGBu8.hpp"
#ifndef __IOPPM__HPP
#define __IOPPM__HPP

/// \brief read a P6 PPM image from a file
/// \param filename : file the image name (PPM, P6 = RGB, binaray)
/// \param image : image to fill
/// \return : EXIT_SUCCESS if the image is loaded correctly, EXIT_FAILURE otherwise
int readPPM(const std::string &filename, ImageRGBu8 &image);

/// \brief write an image from a file (PPM, P6 = RGB, binaray)
/// \param filename : file the image name 
/// \param image : image to save
/// \return : EXIT_SUCCESS if the image is saved correctly, EXIT_FAILURE otherwise
int writePPM(const std::string &filename, const ImageRGBu8 &image);

#endif
