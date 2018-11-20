#include <iostream>

class AjoutSiPair {
	public:
		inline int operator()(int n) // La surcharge de l'opérateur ()
		{
			return (n%2 == 0) ? n+10 : n;
		}
};