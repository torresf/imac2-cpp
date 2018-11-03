#ifndef __CARRE__HPP
#define __CARRE__HPP

#include "Rectangle.hpp"

class Carre : public Rectangle {
	private:
		double _cote;

	public:
		Carre();
		Carre(const double &c);
		~Carre();

		inline double getCote() const { return _cote; };
		inline void setCote(const double &c) { _cote = c; };

		std::string quiSuisJe() const;
};

#endif