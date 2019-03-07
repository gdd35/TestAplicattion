#pragma once

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Coin {

	public:
			float up, down, right, left;
			Sprite coinSprite;

			Coin(){}

			Coin(string coin, RenderWindow &window) {
				if (!coinTexture.loadFromFile(coin)) {
					cerr << "ERROR" <<endl;
				}
				coinTexture.setSmooth(true);
				coinSprite.setTexture(coinTexture);
				coinSprite.setTextureRect(IntRect(0, 0, 100, 110));
				srand(time(NULL));
				position.y = rand() % window.getSize().x;
				position.y = rand() % window.getSize().y;
				coinSprite.setPosition(position.x, position.y);

				coinSprite.setScale(0.25, 0.25);
			}

			void drawCoin(RenderWindow &window) {
				window.draw(coinSprite);
			}
			// Animation coin

			void animationCoin() {
				countAnimation++;
				coinSprite.setTextureRect(IntRect(100 * countAnimation, 0, 100, 110));
				if (countAnimation == 5) {
					countAnimation = 0;
				}
			}
			// mSprite.getPosition().x + (mSprite.getGlobalBounds().width / 4) esto me da la posicion izquierda de la moneda. o lo mismo que multiplicar el tamaño por 0.25
			// mSprite.getPosition().x + (mSprite.getGlobalBounds().width *0.75) parte derecha de la moneda
			// mSprite.getPosition().y + (mSprite.getGlobalBounds().height *0.75 parte de abajo de la moneda
			// mSprite.getPosition().y + (mSprite.getGlobalBounds().height*0.25) parte de arriba de la moneda


			void updateCoin() {
				up = coinSprite.getPosition().y + (coinSprite.getGlobalBounds().height*0.25);
				down = coinSprite.getPosition().y + (coinSprite.getGlobalBounds().height *0.75);
				right = coinSprite.getPosition().x + (coinSprite.getGlobalBounds().width *0.75);
				left = coinSprite.getPosition().x + (coinSprite.getGlobalBounds().width * 0.25);
			}
	private:
			Texture coinTexture;
			Vector2i position;
			int countAnimation = 0;
};