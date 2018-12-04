#ifndef __POINT3D__HPP
#define __POINT3D__HPP

#include <iostream>

template<typename Type>
class Point3D
{
	private: 
		Type m_x;
		Type m_y;
		Type m_z;

	public:
		Point3D()
			:m_x(0),m_y(0),m_z(0)
		{}

		Point3D(const Type &x, const Type &y, const Type &z)
			:m_x(x),m_y(y),m_z(z)
		{}

		template<typename Type2>
		Point3D<Type>(const Point3D<Type2> &p)
			:m_x(p.getX()),m_y(p.getY()),m_z(p.getZ()) 
		{}

		// Destructeur
		~Point3D(){};
	
		Point3D &operator=(const Point3D &p) const 
		{ 
			if (this != &p)
			{
				m_x = p.m_x;
				m_y = p.m_y;
				m_z = p.m_z;
			}
		    return *this;
		}

		Point3D operator+(const Type &n) const 
		{ 
			return Point3D(m_x+n, m_y+n, m_z+n);
		}

		Point3D operator+(const Point3D &p) const
		{
			return Point3D(m_x + p.m_x, m_y + p.m_y, m_z + p.m_z);
		}

		friend std::ostream &operator<<(std::ostream &os, const Point3D &p)
		{
			os << '[' << p.m_x << ", " << p.m_y << ", " << p.m_z << ']';
			return os;
		}

		inline Type getX() const {
			return m_x;
		}

		inline Type getY() const {
			return m_y;
		}

		inline Type getZ() const {
			return m_z;
		}

		const Type& operator[](const size_t &i) const {
			switch (i) {
				case 0: return m_x;
				case 1: return m_y;
				case 2: return m_z;
				default: break; // Exception
			}
		}

		Type& operator[](const size_t &i) {
			switch (i) {
				case 0:
					return m_x;
					break;
				case 1: 
					return m_y;
					break;
				case 2:
					return m_z;
					break;
				default: 
					break;
			}
		}
};


#endif