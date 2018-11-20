#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

#include <fstream>


#ifndef __VECTORD__HPP
#define __VECTORD__HPP


/// \class VectorD
/// \brief class defining a vector for linear algebra operations.
class VectorD {

public:

	/// \brief constructor from a size
	/// \param size : the size of the requested vector
    VectorD(const size_t size);

	/// \brief copy-constructor
	/// \param v : the source vector to be copied
	VectorD(const VectorD & v);

    /// \brief destructor
    ~VectorD();


private :
  
    size_t _size;     /*!< size of the vector */

    double * _data;   /*!< address of the data array */


public :
	
	/// \brief return the size of a Vector
	inline size_t size() const {
		return _size;
	}

	/// \brief affectation operator
	VectorD & operator=(const VectorD &v);

	/// \brief operator to access to the ist element of a vector
	double& operator[](const size_t& i);

	/// \brief operator to access to the ist element of a vector (const version)
	const double& operator[](const size_t& i) const;

	/// \brief add 2 vectors of same size
	VectorD operator+(const VectorD &v) const;

	/// \brief normalize a vector such its norm is 1.
    void normalize();

    /// \brief compute the inner product between 2 vectors
    /// \param v : the second vector to consider in the dot product.
    /// \return : the scalar value corresponding to the dot product. 
    double dot(const VectorD &v) const;

    /// \brief computes the cross product between 2 vectors
    /// \param v : the second vector to consider in the cross product, of size 3.
    /// \return vector of size 3
    VectorD cross(const VectorD &v) const;

    /// \brief save a vector in a file
    int save(const std::string &filename) const;

    /// \brief load a vector from a file, the size of the vector should be already the good one ...
    int load(const std::string &filename);

    /// \brief display the elements of the vector
    void display()const;

};

	/// \brief overload the operator << for VectorD
    std::ostream& operator<< (std::ostream& stream, const VectorD& v);

#endif
