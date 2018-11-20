#include <iostream>
#include <cstdlib>

#include "VectorD.hpp"


// g++ -Wall -O2 main.cpp VectorD.cpp -o vec.exe

void print(const VectorD &v, const size_t &i )
{
	std::cout << v[i] << std::endl;
}


int main(int argc, char **argv) {

    VectorD v(3);
/*
    // tp2
    v._data[0] = 1.0;
    v._data[1] = 0.3;
    v._data[2] = 5.2;
*/

    // tp3
    v[0] = 1.0;
    v[1] = 0.3; 
    v[2] = 5.2;

    v.display();

    VectorD v2 = v;
    v2.normalize();
    v2.display();

    v = v + v2;
    v.display();


    std::cout << "Dot product " <<  v.dot(v2) << std::endl;

    VectorD v3 = v.cross(v2);

    v.save("/tmp/vec.txt");

    VectorD v4(3);
    v4.load("/tmp/vec.txt");

    std::cout << v4 << std::endl;

    return(EXIT_SUCCESS);
}
