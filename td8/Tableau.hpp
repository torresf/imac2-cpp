#ifndef __TABLEAU__HPP
#define __TABLEAU__HPP

#include <iostream>
#include "Error.hpp"

template<typename T, int N>
class Tableau
{
	private: 
		T *m_data;
		unsigned int m_size;

	public:
		Tableau()
			:m_size(0) 
		{
			m_data = new T[N];
		}

		~Tableau() {
			delete[] m_data;
		}

		bool isEmpty() const {
			return (m_size <= 0) ? true : false;
		}

		unsigned int getSize() const {
			return m_size;
		}

		int getMaxSize() const {
			return N;
		}

		T getFirst() const {
			if (isEmpty())
				throw Error(1, 1, std::string(__FILE__), __LINE__, "Le tableau est vide.");
			else
				return m_data[0];
		}

		T getLast() const {
			if (isEmpty())
				throw Error(1, 1, std::string(__FILE__), __LINE__, "Le tableau est vide.");
			else
				return m_data[m_size-1];
		}

		T operator[](const unsigned int &n) const 
		{
			return m_data[n];
		}

		T &operator[](const unsigned int &n) 
		{
			return m_data[n];
		}

		T at(const unsigned int &n) const
		{
			if (isEmpty() || n > m_size)
				throw Error(1, 2, std::string(__FILE__), __LINE__, "Indice non valide. L'élément n'existe pas.");
			else
				return m_data[n];
		}

		T &at(const unsigned int &n)
		{
			if (isEmpty() || n > m_size-1)
				throw Error(1, 2, std::string(__FILE__), __LINE__, "L'élément n'existe pas.");
			else
				return m_data[n];
		}

		void push(const T &n) {
			if (m_size >= N) {
				throw Error(1, 3, std::string(__FILE__), __LINE__, "Le tableau est plein.");
			} else {
				m_data[m_size] = n;
				m_size++;
			}
		}

		void pop() {
			if (isEmpty()) {
				throw Error(1, 1, std::string(__FILE__), __LINE__, "Le tableau est déjà vide.");
			} else {
				m_data[m_size] = 0;
				if (m_size > 0)
					m_size--;
			}
		}

		void insert(const unsigned int &index, const T &value) {
			if (m_size >= N) {
				throw Error(1, 3, std::string(__FILE__), __LINE__, "Le tableau est plein.");
			} else if (index > m_size-1) {
				throw Error(1, 2, std::string(__FILE__), __LINE__, "Indice invalide.");
			} else {
				for (unsigned int i = m_size; i > index; --i)
				{
					m_data[i] = m_data[i-1];
				}
				m_data[index] = value;
				m_size++;
			}
		}

		void erase(const unsigned int &index) {
			if (isEmpty()) {
				throw Error(1, 1, std::string(__FILE__), __LINE__, "Le tableau est vide.");
			} else if (index > m_size-1) {
				throw Error(1, 2, std::string(__FILE__), __LINE__, "Indice invalide.");
			} else {
				for (unsigned int i = index; i < m_size; ++i)
					m_data[i] = m_data[i+1];
				m_size--;
			}
		}

		friend std::ostream &operator<<(std::ostream &os, const Tableau &t)
		{
			os << "[ ";
			for (unsigned int i = 0; i < t.getSize(); ++i)
			{
				os << t.at(i) << ' ';
			}
			os << ']';
			return os;
		}

};

#endif