#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Moneda {

	public:
			Moneda(){}
			Moneda(string moneda	) {
				if (!mTexture.loadFromFile(moneda)) {
					cerr << "Error \n";
				}
				mTexture.setSmooth(true);
				mSprite.setTexture(mTexture);
				mSprite.setTextureRect(IntRect(0, 0, 100, 110)); // Posicion inicial del sprite
				mSprite.setPosition(400, 300); // Posicion para testear
				mSprite.setScale(0.25, 0.25); // Escala para testear
			}

			void dibujarMoneda(RenderWindow &window) {
				window.draw(mSprite);
			}

			// Animacion moneda

			void actualizarMoneda() {
				contador++;
				mSprite.setTextureRect(IntRect(100 * contador, 0, 100, 110));
				if (contador == 5) {
					contador = 0;
				}
			}
	private:
		Texture mTexture;
		Sprite mSprite;
		int contador = 0;
};