#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Background {

public:
		Background() {}
		Background(string background, RenderWindow &window) {

		backgroundImage.create(window.getSize().x, window.getSize().y); 

#pragma region Understand Window Size
		// Creo una imagen, con este tamaño que seria el de la ventana, al poner directamente que obtenga el valor de la ventana que le pase por
		// parametro, si vos agrandas esa ventana, la imagen iria acorde a eso
#pragma endregion

		backgroundImage.loadFromFile(background); // Luego, cargo esa imagen desde un archivo que es el que paso por parametro

		if (!backgroundTexture.loadFromImage(backgroundImage)) // Set texture
		{
			cerr << "ERROR" << endl;
		}
				backgroundTexture.setSmooth(true);
				backgroundSprite.setTexture(backgroundTexture); // Set sprite to draw
			}
	void drawBackground(RenderWindow &window) {
		window.draw(backgroundSprite);
	}


	private:
			Texture backgroundTexture;
			Sprite backgroundSprite;
			Image backgroundImage;
};
