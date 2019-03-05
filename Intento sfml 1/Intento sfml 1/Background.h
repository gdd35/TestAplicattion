#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Background {

public:
		Background() {}
		Background(string imagen, RenderWindow &window) {

		bImage.create(window.getSize().x, window.getSize().y); 

#pragma region Entender tamaño ventana
		// Creo una imagen, con este tamaño que seria el de la ventana, al poner directamente que obtenga el valor de la ventana que le pase por
		// parametro, si vos agrandas esa ventana, la imagen iria acorde a eso
#pragma endregion

		bImage.loadFromFile(imagen); // Luego, cargo esa imagen desde un archivo que es el que paso por parametro

		if (!bTexture.loadFromImage(bImage)) // Se le carga a la textura
		{
			cerr << "Error \n";
		}
				bTexture.setSmooth(true);
				bSprite.setTexture(bTexture); // Luego al sprite, asi puedo dibujarlo
			}
	void dibujarBackground(RenderWindow &window) {
		window.draw(bSprite);
	}


	private:
			Texture bTexture;
			Sprite bSprite;
			Image bImage;
};
