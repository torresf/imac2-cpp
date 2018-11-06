#ifndef __ELLIPSE__HPP
#define __ELLIPSE__HPP

#include <math.h>
#include "Figure.hpp"

class Ellipse : public Figure {
	protected:
		double _radiusX;
		double _radiusY;

	public:
		Ellipse();
		Ellipse(const double &rx, const double &ry);
		~Ellipse();

		inline double getRadiusX() const { return _radiusX; };
		inline double getRadiuxY() const { return _radiusY; };

		inline void setRadiusX(const double &rx) { _radiusX = rx; };
		inline void setRadiuxY(const double &ry) { _radiusY = ry; };
		
		inline double surface() const { return M_PI * _radiusX * _radiusY; };

		void quiSuisJe() const;
};

#endif