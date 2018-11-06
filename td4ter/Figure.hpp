#ifndef __FIGURE__HPP
#define __FIGURE__HPP

class Figure {
	public:
		Figure();
		virtual ~Figure();

		virtual double surface() const =0;
		virtual void quiSuisJe() const;
};

#endif