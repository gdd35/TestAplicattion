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

		/* I create an image, with this size that would be the one in the window */

#pragma endregion

		backgroundImage.loadFromFile(background); // Set image with parameters

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
