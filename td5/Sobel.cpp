#include "Sobel.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>


// Constructeurs
Sobel::Sobel() {}

// Destructeur
Sobel::~Sobel() {}

// Méthodes 
void Sobel::applyFilter(ImageRGBu8 &image) {
	std::cout << "applyFilter Sobel" << std::endl;

	// On stocke l'image originale dans une variable temporaire pour ne pas analyser les pixels déjà modifiés
	ImageRGBu8 tempImage(image);
	std::vector<int> pixels;
	int index;
	int dataLength = image.width() * image.height() * 3;

	int x = 0;
	int y = 0;
	int G = 0;

	std::vector<std::vector<int>> Gx{{1, 0, -1},
									 {2, 0, -2},
									 {1, 0, -1}};

	std::vector<std::vector<int>> Gy{{ 1,  2,  1},
									 { 0,  0,  0},
									 {-1, -2, -1}};

	for (int i = 0; i < 3; ++i) // Boucle sur les 3 couleurs
	{
		for (int j = 0; j < dataLength; j+=3) // Boucle sur tous les pixels
		{
			// On vide le tableau de pixels
			pixels.clear();
			std::fill(pixels.begin(), pixels.end(), 0); // Remplir le tableau avec des 0

			// Boucle sur les pixels adjacents (pour une matrice 3x3)
			for (int k = -1; k <= 1; ++k)
			{
				for (int l = -1; l <= 1; ++l)
				{
					// Ajout du pixel
					index = (j+i + (l * image.width() * 3) + (k * 3));
					if (index >= 0 && index <= (int)dataLength)
					{
						pixels.push_back(tempImage.data()[index] * Gx[k+1][l+1]);
					}
				}
			}

			x = 0;
			for (unsigned int a = 0; a < pixels.size(); ++a)
			{
				x += pixels[a];
			}

			// On vide le tableau de pixels
			pixels.clear();
			std::fill(pixels.begin(), pixels.end(), 0); // Remplir le tableau avec des 0

			// Boucle sur les pixels adjacents (pour une matrice 3x3)
			for (int k = -1; k <= 1; ++k)
			{
				for (int l = -1; l <= 1; ++l)
				{
					// Ajout du pixel
					index = (j+i + (l * image.width() * 3) + (k * 3));
					if (index >= 0 && index <= (int)dataLength)
					{
						pixels.push_back(tempImage.data()[index] * Gy[k+1][l+1]);
					}
				}
			}

			y = 0;
			for (unsigned int a = 0; a < pixels.size(); ++a)
			{
				y += pixels[a];
			}

			G = std::sqrt(x*x + y*y);

			if (G > 255)
			{
				G = 255;
			}
			// Affectation de la nouvelle valeur
			std::cout << G << std::endl;
			image.data()[j+i] = G;
		}
	}
}