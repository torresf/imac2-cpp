#ifndef __MAGE__HPP
#define __MAGE__HPP

#include "Personnage.hpp"

class Mage : public Personnage
{	
	private:
		int _mana;
	
	public:
		Mage();
		~Mage();

	void quiSuisJe() const;

	inline int getMana() const {
		return _mana;
	}

	inline void setMana(const int m) {
		_mana = m;
	}

	void getInfos();
};

#endif