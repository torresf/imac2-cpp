#ifndef __RECTANGLE__HPP
#define __RECTANGLE__HPP

class Rectangle {
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

		std::string quiSuisJe() const;
};

#endif