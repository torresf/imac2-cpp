#include <sstream>
#include <fstream>

#include "ioPPM.hpp"

int readPPM(const std::string &filename, ImageRGBU8 & image) {	

	// open file
	std::ifstream file(filename, std::ifstream::in);

	// check if the file is correctly opened
	if(! file.is_open()){
		std::cerr << "readPPM : error while opening : " << filename << std::endl;
		return EXIT_FAILURE;
	}
	
	// image format (suposed P6 => ignored)
	std::string line;
	std::getline(file,line);
	
	// comments (to ignore)
	std::getline(file,line);
	while(line[0]=='#'){
		std::getline(file,line);
	}	

	// image dimension
	std::istringstream ist(line);
	int w,h;
	ist >> w >> h;

	// read max value (supposed 255 => ignored)
	std::getline(file,line);

	// read data
#if 0 
	// May be necessary on windows	   
    unsigned int dataStart = file.tellg();	
    file.close();
    file.open(filename.c_str(),std::ios::in | std::ios::binary); 
    file.seekg(dataStart);
#endif
	std::vector<unsigned char> dataVector(w*h*3);
	file.read((char*) dataVector.data(), w*h*sizeof(unsigned char)*3);

	// close the file
	file.close();

	// buld the image from the data
	image = ImageRGBU8(w,h,dataVector);

	return EXIT_SUCCESS;
}


int writePPM(const std::string &filename, const ImageRGBU8 & image) {	

	// open the file
	std::ofstream file(filename, std::ofstream::out);

	// check if the file is correctly opened
	if(! file.is_open()){
		std::cerr << "writePPM : error while opening : " << filename << std::endl;
		return EXIT_FAILURE;
	}

	// format
	file << "P6" << std::endl;

	// comments 
	file << "# By imac" << std::endl;

	// dimensions
	file << image.width() << " " << image.height() << std::endl;

	// max value
	file << 255 << std::endl;
		
	// write data
 	file.write( (char*)image.data(), image.width()*image.height()*sizeof(unsigned char)*3 );

 	// close file
	file.close();

	return EXIT_SUCCESS;
}
