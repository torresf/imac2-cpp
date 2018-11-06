#ifndef __RECTANGLE__HPP
#define __RECTANGLE__HPP

#include "Figure.hpp"

class Rectangle : public Figure {
	protected:
		double _largeur;
		double _hauteur;

	public:
		Rectangle();
		Rectangle(const double &l, const double &h);
		~Rectangle();

		inline double getLargeur() const { return _largeur; };
		inline double getHauteur() const { return _hauteur; };

		inline void setLargeur(const double &l) { _largeur = l; };
		inline void setHauteur(const double &h) { _hauteur = h; };
		
		inline double surface() const { return _largeur * _hauteur; };

		void quiSuisJe() const;
};

#endif