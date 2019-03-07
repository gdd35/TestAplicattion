#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>

#include "Player.h"
#include <SFML/Graphics.hpp>

class Score {

	public:	

		void showScore(RenderWindow &window ,Player &player) {
			if (!font.loadFromFile("Fonts/Gobold Uplow.ttf")) {
				cout << "ERROR" << endl;
			}
			score.setFont(font);
			score.setPosition(window.getSize().x / 2, 0);
			score.setString(to_string(player._score));
			window.draw(score);
		}

	private:
			Text score;
			Font font;
};
