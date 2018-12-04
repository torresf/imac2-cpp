#ifndef __TABLEAU__HPP
#define __TABLEAU__HPP

#include <iostream>
#include "Error.hpp"

template<typename T, size_t N>
class Tableau
{
	private: 
		T m_data[N];
		size_t m_size;

	public:
		Tableau()
			:m_size(0) 
		{
			for (size_t i = 0; i < N; ++i)
			{
				m_data[i] = 0;
			}
		}

		~Tableau() {}

		bool isEmpty() const {
			return m_size == 0;
		}

		size_t getSize() const {
			return m_size;
		}

		size_t getMaxSize() const {
			return N;
		}

		const T& first() const {
			if (isEmpty())
				throw Error(1, 1, std::string(__FILE__), __LINE__, "Le tableau est vide.");
			else
				return m_data[0];
		}

		T& first() {
			if (isEmpty())
				throw Error(1, 1, std::string(__FILE__), __LINE__, "Le tableau est vide.");
			else
				return m_data[0];
		}

		const T& last() const {
			if (isEmpty())
				throw Error(1, 1, std::string(__FILE__), __LINE__, "Le tableau est vide.");
			else
				return m_data[m_size-1];
		}

		T& last() {
			if (isEmpty())
				throw Error(1, 1, std::string(__FILE__), __LINE__, "Le tableau est vide.");
			else
				return m_data[m_size-1];
		}

		const T& operator[](const size_t &n) const
		{
			return m_data[n];
		}

		T& operator[](const size_t &n)
		{
			m_size = (n+1) > m_size ? (n+1) : m_size;
			return m_data[n];
		}

		T at(const size_t &n) const
		{
			if (isEmpty() || n > m_size)
				throw Error(1, 2, std::string(__FILE__), __LINE__, "Indice non valide. L'élément n'existe pas.");
			return m_data[n];
		}

		T &at(const size_t &n)
		{
			if (isEmpty() || n > m_size-1)
				throw Error(1, 2, std::string(__FILE__), __LINE__, "L'élément n'existe pas.");
			return m_data[n];
		}

		void push(const T &n) {
			if (m_size >= N) 
				throw Error(1, 3, std::string(__FILE__), __LINE__, "Le tableau est plein.");
			m_data[m_size] = n;
			m_size++;
		}

		void pop() {
			if (isEmpty())
				throw Error(1, 1, std::string(__FILE__), __LINE__, "Le tableau est déjà vide.");
			m_data[m_size] = 0;
			if (m_size > 0)
				m_size--;
		}

		void insert(const size_t &index, const T &value) {
			if (m_size >= N) {
				throw Error(1, 3, std::string(__FILE__), __LINE__, "Le tableau est plein.");
			} else if (index > m_size-1) {
				throw Error(1, 2, std::string(__FILE__), __LINE__, "Indice invalide.");
			} else {
				for (size_t i = m_size; i > index; --i)
				{
					m_data[i] = m_data[i-1];
				}
				m_data[index] = value;
				m_size++;
			}
		}

		void erase(const size_t &index) {
			if (isEmpty())
				throw Error(1, 1, std::string(__FILE__), __LINE__, "Le tableau est vide.");
			else if (index > m_size-1)
				throw Error(1, 2, std::string(__FILE__), __LINE__, "Indice invalide.");
			for (size_t i = index; i < m_size; ++i)
				m_data[i] = m_data[i+1];
			m_size--;
		}

		friend std::ostream &operator<<(std::ostream &os, const Tableau &t)
		{
			os << "[ ";
			for (size_t i = 0; i < t.getSize(); ++i)
				os << t.at(i) << ' ';
			os << ']';
			return os;
		}

};

#endif