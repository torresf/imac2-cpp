#include <iostream>

class Majuscule {
	public:
		inline char operator()(char l) // La surcharge de l'opérateur ()
		{
			return toupper(l);
		}
};