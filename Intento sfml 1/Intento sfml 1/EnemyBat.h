#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"

using namespace std;
using namespace sf;

class Bat {

public:
	float up, down, right, left;
	Bat() {}

	Bat(string batImage) {

		if (!batTexture.loadFromFile(batImage)) {
			cout << "ERROR" << endl;
		}
		batTexture.setSmooth(true);
		batSprite.setTexture(batTexture);
		batSprite.setScale(0.07, 0.07);
		batSprite.setTextureRect(IntRect(0, 0, 2000, 1000));
		speed = 0.1;
		//batSprite.setPosition(0 - batSprite.getGlobalBounds().width, 0);

	}

	void drawBat(RenderWindow &window) {
		window.draw(batSprite);
	}
#pragma region Values of the Bat Enemy

	// batSprite.getPosition().x + batSprite.getGlobalBounds().width*0.85 << endl; derecha
	// batSprite.getPosition().x + batSprite.getGlobalBounds().width*0.08 izquierda
	// batSprite.getPosition().y + batSprite.getGlobalBounds().height*0.12 << endl; arriba
	// batSprite.getPosition().y + batSprite.getGlobalBounds().height*0.95 << endl; abajo

#pragma endregion

	void getBat() {
		up = batSprite.getPosition().y + (batSprite.getGlobalBounds().height*0.12);
		down = batSprite.getPosition().y + (batSprite.getGlobalBounds().height*0.95);
		left = batSprite.getPosition().x + (batSprite.getGlobalBounds().width*0.08);
		right = batSprite.getPosition().x + (batSprite.getGlobalBounds().width*0.85);
	}

	void move(RenderWindow &window, Time time, Clock clock) {
		_time = time;
		_clock = clock;
		_time = clock.getElapsedTime();

		batSprite.move(speed * _time.asMilliseconds(), 0);
		batSprite.setTextureRect(IntRect(2000 * spriteX, spriteY, 2000, 1000));

		if (CollisionLimitsRight(window) == true) {
			speed *= -1;
			spriteY += 1000;

			batSprite.setTextureRect(IntRect(2000 * spriteX, spriteY, 2000, 1000));
			batSprite.setPosition(window.getSize().x - batSprite.getGlobalBounds().width, 0);

		}
		else if (CollisionLimitsLeft() == true) {
			spriteY = 0;
			speed = 0.1;
		}
		spriteX++;
		if (spriteX == 3) {
			spriteX = 0;
		}

		_clock.restart().asMilliseconds();
	}
	bool CollisionLimitsRight(RenderWindow &window) {
		if (right > window.getSize().x + 5) {
			return true;
		}
		return false;
	}
	bool CollisionLimitsLeft() {
		if (left < -5) {
			return true;
		}
		return false;
	}
private:
	Texture batTexture;
	Sprite batSprite;
	Time _time;
	Clock _clock;
	int spriteX = 0, spriteY = 0;
	float speed = 0;
};