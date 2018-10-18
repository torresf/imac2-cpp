class VectorD
{
private:
	// Attributs
	int _size;
	double *_data;

public:
	/* Constructeurs / Destructeur */
	VectorD(const int n); // Constructeur standard
	VectorD(const VectorD &v); // Constructeur par copie
	~VectorD(); // Destructeur

	/* Méthodes liées aux vecteurs */
	void normalize();
	VectorD operator+(const VectorD &v2) const;
	VectorD& operator=(const VectorD &v2);
	int save(const std::string &filename) const;

	/* Accesseurs */
	inline int size() const {
		return _size;
	}

	inline void setSize(const int n) {
		_size = n;
	}

	inline double getValue(const int index) const {
		return _data[index];
	}

	inline void setValue(const int index, const double &value) {
		_data[index] = value;
	}
};