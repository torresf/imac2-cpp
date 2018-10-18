#include <iostream>
#include <tgmath.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include "../include/VectorD.hpp"

// Constructeur standard
VectorD::VectorD(const int n) {
	std::cout << "Constructeur standard" << std::endl;
	_size = n;
	_data = new double[n];
}

// Constructeur par copie
VectorD::VectorD(const VectorD &v):VectorD(v._size) {
	std::cout << "Constructeur par copie" << std::endl;
	std::copy(v._data, v._data + v._size, _data);
}

// Destructeur
VectorD::~VectorD() {
	delete[] _data;
}

/* Méthodes liées aux vecteurs */

void VectorD::normalize() {
	double norm = 0.0;
	for (int i = 0; i < _size; ++i)
		norm += _data[i] * _data[i];
	
	if (fabs(norm) <= 1.0e-10)
		return;

	norm = sqrt(norm);

	for (int i = 0; i < _size; ++i)
		_data[i] /= norm;
}

VectorD VectorD::operator+(const VectorD &v2) const {
	std::cout << "Operator+" << std::endl;
	if (v2._size != _size)
		return *this;
	VectorD v3(_size);
	// for (int i = 0; i < _size; ++i)
	// 	v3._data[i] = _data[i] + v2._data[i];

	// OU : 
	std::transform(_data, _data + _size, v2._data, v3._data, std::plus<double>());
	return v3;
}

VectorD& VectorD::operator=(const VectorD &v2) {
	if (&v2 == this)
		return *this;
	if (v2._size != _size) // en théorie : resize
		return *this;
	std::copy(v2._data, v2._data + v2._size, _data);
	return *this;
}

int VectorD::save(const std::string &filename) const {
	std::ofstream myFile;
	myFile.open(filename, std::ios::out);
	if (!myFile.is_open())
	{
		std::cerr << "Error : à l'ouverture du fichier " << filename << std::endl;
		return EXIT_FAILURE;
	}
	myFile << _size << std::endl;
	for (int i = 0; i < _size; ++i)
	{
		myFile << _data[i] << " ";
	}
	myFile.close();
	return EXIT_SUCCESS;
}