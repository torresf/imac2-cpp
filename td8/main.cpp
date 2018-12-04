#include <iostream>
#include <cctype>
#include <vector>
#include "Point3D.hpp"
#include "Tableau.hpp"
#include "Error.hpp"

template<typename T>
const T &getMinimum(const T &a, const T &b) {
	return a < b ? a : b;
}

template<>
const char &getMinimum<char>(const char &a, const char &b) {
	char c = std::toupper(a);
	char d = std::toupper(b);
	return c < d ? a : b;
}

int main(int argc, char const *argv[])
{

	/* ----- EXO1 ----- */
	std::cout << "\n----- EXO1 -----" << std::endl;
	/* ----- Q1 ----- */
	std::cout << getMinimum(79, 67) << std::endl;
	std::cout << getMinimum(7.9, 6.7) << std::endl;
	std::cout << getMinimum('a', 'z') << std::endl;

	/* ----- Q2 ----- */
	std::cout << getMinimum<float>(1, 2.f) << std::endl;

	/* ----- Q3 ----- */
	std::cout << getMinimum<float>(1, 2.f) << std::endl;
	std::cout << getMinimum('a', 'Z') << std::endl;


	/* ----- EXO2 ----- */
	std::cout << "\n----- EXO2 -----" << std::endl;
	/* ----- Q1 ----- */
	Point3D<int> p1(1, 2, 3), p2(10, 11, 12);
	std::cout << "p1 : " << p1 << std::endl;
	std::cout << "p2 : " << p2 << std::endl;
	std::cout << "p1 + p2 : " << p1 + p2 << std::endl;

	Point3D<float> A(7.9, 6.7, 1.6);
	Point3D<int> B(A);
	std::cout << "A : " << A << std::endl;
	std::cout << "B : " << B << std::endl;


	/* ----- EXO3 ----- */
	std::cout << "\n----- EXO3 -----" << std::endl;
	/* ----- Q2 ----- */
	Tableau<int, 5> t;
	try {
		t.push(1);
		t.push(2);
		t.push(3);
		t.push(4);
		t.push(5);
		t.push(5);
	} 
	catch (const Error &e) {
		std::cerr << e.what() <<  std::endl;
	}
	std::cout << t << std::endl;
	std::cout << t[0] << std::endl;
	t[0] = 15;
	std::cout << t << std::endl;
	t.pop();
	t.pop();
	t.pop();
	t.pop();
	std::cout << t << std::endl;

	try {
		std::cout << t.at(0) << std::endl;
		t.at(0)++;
		std::cout << t.at(0) << std::endl;
		std::cout << t.at(1) << std::endl;
	}
	catch (const Error &e) {
		std::cerr << e.what() <<  std::endl;
	}

	try {
		t.pop();
		t.pop();
	}
	catch (const Error &e) {
		std::cerr << e.what() <<  std::endl;
	}
	
	t.push(1);
	t.push(2);
	t.push(3);
	t.push(4);
	std::cout << t << std::endl;
	try {
		std::cout << "Erase(1)" << std::endl;
		t.erase(1);
		std::cout << "Erase(100)" << std::endl;
		t.erase(100);
	}
	catch (const Error &e) {
		std::cerr << e.what() <<  std::endl;
	}
	std::cout << t << std::endl;

	try {
		std::cout << "Insert(1, 10)" << std::endl;
		t.insert(1, 10);
		std::cout << "Insert(100, 10)" << std::endl;
		t.insert(100, 10);
	}
	catch (const Error &e) {
		std::cerr << e.what() <<  std::endl;
	}
	std::cout << t << std::endl;


	try {
		std::cout << "first()" << std::endl;
		std::cout << t.first() << std::endl;
	}
	catch (const Error &e) {
		std::cerr << e.what() <<  std::endl;
	}

	try {
		std::cout << "last()" << std::endl;
		std::cout << t.last() << std::endl;
	}
	catch (const Error &e) {
		std::cerr << e.what() <<  std::endl;
	}

	return 0;
}