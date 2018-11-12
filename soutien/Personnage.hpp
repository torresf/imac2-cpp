#ifndef __PERSONNAGE__HPP
#define __PERSONNAGE__HPP

#include <iostream>

class Personnage
{
	protected:
		int _vie;
		int _degats;

	public:
		Personnage();
		Personnage(const int v, const int d);
		~Personnage();
	
	// Accesseurs : Getters / Setters
	inline int getVie() const {
		return _vie;
	}

	inline int getDegats() const {
		return _degats;
	}

	inline void setVie(const int v) {
		_vie = v;
	}

	inline void setDegats(const int d) {
		_degats = d;
	}

	virtual void getInfos();

	virtual void quiSuisJe() const;

	void attaquer(Personnage &p);
};

#endif