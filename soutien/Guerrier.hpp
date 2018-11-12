#ifndef __GUERRIER__HPP
#define __GUERRIER__HPP

#include "Personnage.hpp"

class Guerrier : public Personnage
{
	public:
		Guerrier();
		~Guerrier();

	void quiSuisJe() const;
};

#endif