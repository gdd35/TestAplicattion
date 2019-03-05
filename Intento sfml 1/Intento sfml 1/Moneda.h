#pragma once

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Moneda {

	public:
			float arriba, abajo, derecha, izquierda;
			Sprite mSprite;

			Moneda(){}

			Moneda(string moneda, RenderWindow &window) {
				if (!mTexture.loadFromFile(moneda)) {
					cerr << "Error \n";
				}
				mTexture.setSmooth(true);
				mSprite.setTexture(mTexture);
				mSprite.setTextureRect(IntRect(0, 0, 100, 110));

				posicion.x = rand() % window.getSize().x;
				posicion.y = rand() % window.getSize().y;
				mSprite.setPosition(posicion.x, posicion.y);

				mSprite.setScale(0.25, 0.25);
			}

			void dibujarMoneda(RenderWindow &window) {
				window.draw(mSprite);
			}
			// Animacion moneda

			void animacionMoneda() {
				contador++;
				mSprite.setTextureRect(IntRect(100 * contador, 0, 100, 110));
				if (contador == 5) {
					contador = 0;
				}
			}
			// mSprite.getPosition().x + (mSprite.getGlobalBounds().width / 4) esto me da la posicion izquierda de la moneda. o lo mismo que multiplicar el tamaño por 0.25
			// mSprite.getPosition().x + (mSprite.getGlobalBounds().width *0.75) parte derecha de la moneda
			// mSprite.getPosition().y + (mSprite.getGlobalBounds().height *0.75 parte de abajo de la moneda
			// mSprite.getPosition().y + (mSprite.getGlobalBounds().height*0.25) parte de arriba de la moneda


			void actualizarMoneda() {
				arriba = mSprite.getPosition().y + (mSprite.getGlobalBounds().height*0.25);
				abajo = mSprite.getPosition().y + (mSprite.getGlobalBounds().height *0.75);
				derecha = mSprite.getPosition().x + (mSprite.getGlobalBounds().width *0.75);
				izquierda = mSprite.getPosition().x + (mSprite.getGlobalBounds().width * 0.25);
			}
	private:
			Texture mTexture;
			Vector2i posicion;
			int contador = 0;
};