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

	Coin() {}

	Coin(string coin, RenderWindow &window) {
		if (!coinTexture.loadFromFile(coin)) {
			cerr << "ERROR" << endl;
		}
		coinTexture.setSmooth(true);
		coinSprite.setTexture(coinTexture);
		coinSprite.setTextureRect(IntRect(0, 0, 100, 110));
		srand(time(NULL));
		changePosition(window);
		coinSprite.setScale(0.25, 0.25);
	}

	void drawCoin(RenderWindow &window) {
		window.draw(coinSprite);
	}

	void animationCoin() {
		countAnimation++;
		coinSprite.setTextureRect(IntRect(100 * countAnimation, 0, 100, 110));
		if (countAnimation == 5) {
			countAnimation = 0;
		}
	}
#pragma region Values of the coin (size)

	// mSprite.getPosition().x + (mSprite.getGlobalBounds().width / 4) esto me da la posicion izquierda de la moneda. o lo mismo que multiplicar el tamaño por 0.25
	// mSprite.getPosition().x + (mSprite.getGlobalBounds().width *0.75) parte derecha de la moneda
	// mSprite.getPosition().y + (mSprite.getGlobalBounds().height *0.75 parte de abajo de la moneda
	// mSprite.getPosition().y + (mSprite.getGlobalBounds().height*0.25) parte de arriba de la moneda

#pragma endregion


	void getValuesCoin() {
		up = coinSprite.getPosition().y + (coinSprite.getGlobalBounds().height*0.25);
		down = coinSprite.getPosition().y + (coinSprite.getGlobalBounds().height *0.75);
		right = coinSprite.getPosition().x + (coinSprite.getGlobalBounds().width *0.75);
		left = coinSprite.getPosition().x + (coinSprite.getGlobalBounds().width * 0.25);
	}

	// Change the value of the position randomly
	void changePosition(RenderWindow &window) {
		position.x = rand() % window.getSize().x;
		position.y = rand() % window.getSize().y;
		coinSprite.setPosition(position.x, position.y);
	}
private:
	Texture coinTexture;
	Vector2i position;
	int countAnimation = 0;
};