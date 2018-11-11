#include "Mean.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

// Constructeurs
Mean::Mean():_kernelSize(1) {}
Mean::Mean(const int k):_kernelSize(k) {}

// Destructeur
Mean::~Mean() {}

// Méthodes 
void Mean::applyFilter(ImageRGBu8 &image) {
	std::cout << "applyFilter Mean" << std::endl;

	// On stocke l'image originale dans une variable temporaire pour ne pas analyser les pixels déjà modifiés
	ImageRGBu8 tempImage(image);
	std::vector<int> pixels;
	int index;
	int dataLength = image.width() * image.height() * 3;

	for (int i = 0; i < 3; ++i) // Boucle sur les 3 couleurs
	{
		for (int j = 0; j < dataLength; j+=3) // Boucle sur tous les pixels
		{
			// Récupérer les pixels adjacents, les trier par ordre croissant puis prendre le _kernelSize/2 (arrondi à l'inférieur) ième 
			// On vide le tableau de pixels
			pixels.clear();

			// Boucle sur les pixels adjacents (pour une matrice 3x3)
			for (int k = -_kernelSize; k <= _kernelSize; ++k)
			{
				for (int l = -_kernelSize; l <= _kernelSize; ++l)
				{
					// Ajout du pixel
					index = (j+i + (l * image.width() * 3) + (k * 3));
					if (index >= 0 && index <= (int)dataLength)
					{
						pixels.push_back(tempImage.data()[index]);
					}
				}
			}

			// Tri du tableau
			std::sort(pixels.begin(), pixels.end());

			// Affectation de la nouvelle valeur
			image.data()[j+i] = pixels[pixels.size()/2]; // Pixels.size()/2 correspond à l'index de la valeur médiane du vecteur
		}
	}
}