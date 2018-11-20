#include "VectorD.hpp"

#include <fstream>
#include <cstdlib>    // size_t
#include <algorithm>  // transform



VectorD::VectorD(const size_t size) : _size(size) {
    //std::cout << "Constructeur standard" << std::endl;
    _data = new double[size];
}

VectorD::VectorD(const VectorD & v) : VectorD(v._size){
    //std::cout << "Constructeur par recopie "<< std::endl;
	std::copy(v._data,v._data+v._size,_data);    
}


VectorD::~VectorD() {
    //std::cout << "Destruction" << std::endl;
    delete[] _data;
}

VectorD & VectorD::operator=(const VectorD &v){
	if(&v == this) return *this;

	if(v._size != this->_size){
		std::cerr << "error: VectorD::operator=: operand with incompatible size" << std::endl;
		return *this;
	}

	std::copy(v._data,v._data+v._size, _data);

	return *this;
}

double& VectorD::operator[](const size_t& i){
	return _data[i];
}

const double& VectorD::operator[](const size_t& i) const
{
	return _data[i];
}

VectorD VectorD::operator+(const VectorD &v) const
{
	if(v._size != this->_size){
		std::cerr << "error: VectorD::operator+: operand with incompatible size" << std::endl;
		return *this;
	}

	VectorD tmp(_size);
	std::transform(_data, _data+_size, v._data, tmp._data, std::plus<double>());

	return tmp;
}

void VectorD::display() const {
	for(size_t i=0; i< _size; ++i)
		std::cout << _data[i] << " ";
	std::cout << std::endl;
}


void VectorD::normalize() {
    double norm = 0.0;
	
    for (unsigned int i =0; i<_size; i++) 
        norm += _data[i]*_data[i];
    norm = sqrt(norm);
    
    if (!norm)
        return;
    
    for (unsigned int i =0; i<_size; i++) 
        _data[i] /= norm;
}

double VectorD::dot(const VectorD & v) const {
    if (_size != v._size ) {
        std::cerr << "Erreur dans la taille du vecteur " << std::endl;
        exit(EXIT_FAILURE);
    }    
    double result = 0.0;
    for(unsigned int i=0; i<_size; ++i)
    	result += _data[i]*v._data[i];

    return result;
}

VectorD VectorD::cross(const VectorD & v) const {
    if ((_size!=3) && (v._size!=3)){
        std::cerr << "Erreur dans la taille du vecteur " << std::endl;
        exit(EXIT_FAILURE);
    }    
    
    VectorD vr(3);
    
    vr._data[0] = (_data[1]-v._data[2]) * (_data[2]-v._data[1]);
    vr._data[1] = (_data[2]-v._data[0]) * (_data[0]-v._data[2]);
    vr._data[0] = (_data[0]-v._data[1]) * (_data[1]-v._data[0]);

    return vr;
}


int VectorD::save(const std::string &filename) const{

	//open the file
	std::ofstream myfile;
	myfile.open(filename, std::ios::out | std::ios::binary);
	
    if(!myfile.is_open()){
        std::cerr << "error: can not create file: " << filename << std::endl;
        return EXIT_FAILURE;
    }

	// write the vector size
	myfile << _size << std::endl;

	for(size_t i=0; i<_size; ++i)
		myfile << _data[i] << " ";

	myfile.close();

	return EXIT_SUCCESS;
}

int VectorD::load(const std::string &filename){

	//open the file
	std::ifstream myfile;
	myfile.open(filename, std::ios::in | std::ios::binary);
	
    if(!myfile.is_open()){
        std::cerr << "error: can not open file: " << filename << std::endl;
        return EXIT_FAILURE;
    }

	// read the vector size
	unsigned int vectorSize;
	myfile >> vectorSize;
	std::cout << "vector size: " << vectorSize << std::endl; 
	if(vectorSize != _size){
		myfile.close();
        std::cerr << "vector size error in " << filename << std::endl;
        return EXIT_FAILURE;
	}

	for(size_t i=0; i<vectorSize; ++i){
		myfile >> _data[i];
		std::cout << _data[i] << std::endl;
	}

	myfile.close();

	return EXIT_SUCCESS;
}


std::ostream& operator<< (std::ostream& stream, const VectorD& v) {
	if(v.size() == 0){
		stream << "Not initialized yet -> size is 0";
		return stream;
	}
			
	stream << "(";
	for(unsigned int i=0; i<v.size()-1; ++i)
		stream << v[i] << " , ";
 
 	stream << v[v.size()-1] << ")";

	return stream;
}