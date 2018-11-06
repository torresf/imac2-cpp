#ifndef __CERCLE__HPP
#define __CERCLE__HPP

#include "Ellipse.hpp"

class Cercle : public Ellipse {
	private:
		double _radius;

	public:
		Cercle();
		Cercle(const double &r);
		~Cercle();

		inline double getCote() const { return _radius; };
		inline void setCote(const double &r) { _radius = r; };

		void quiSuisJe() const;
};

#endif