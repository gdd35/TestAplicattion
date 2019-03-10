#pragma region Headers

#include "pch.h"
#include "Player.h"
#include "Coin.h"
#include "Background.h"
#include "Score.h"
#include "EnemyBat.h"

#pragma endregion

#pragma region Libraries

#include <iostream>   
#include <SFML/Graphics.hpp>

#pragma endregion

using namespace std;
using namespace sf;

Vector2f SizeStartWindow(800, 600);

int main()
{
	RenderWindow window(VideoMode(SizeStartWindow.x, SizeStartWindow.y), "Al fin me anduvo esta mierda concha la lora", sf::Style::Titlebar | sf::Style::Close);

	Player player("Sprites/movimiento_player.png", window);
	Coin coin("Sprites/moneda.png", window);
	Background background("Sprites/background.png", window);
	Score score;
	Bat enemyBat("Sprites/Bat_Fly.png");

	Clock clock;
	Time time;

	Event event;

#pragma region Declarations

	window.setFramerateLimit(15);
	window.setKeyRepeatEnabled(false);

#pragma endregion

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) {
					window.close();
					return EXIT_SUCCESS;
				}
			}
		}
		while (player._life != 0) {
			time = clock.getElapsedTime();

			// Move of the Player
			player.move(time, clock);

			enemyBat.move(window, time, clock);

			clock.restart().asMilliseconds();

			// Animation coin
			coin.animationCoin();

			window.clear();

#pragma region Order to draw the sprite

			/* You have to be careful when putting the sprites, since they overlap, I think the correct order would be:
			   background-> platforms -> player -> enemy -> coin */

#pragma endregion

			background.drawBackground(window);

			coin.drawCoin(window);

			enemyBat.drawBat(window);

			player.drawPlayer(window);

			score.showScore(window, player);

			coin.animationCoin();

			player.getPlayer();

			coin.getValuesCoin();

			enemyBat.getBat();


			if (player.CollisionCoin(coin)) {

				coin.changePosition(window);
			}

			if (player.CollisionBat(enemyBat)) {
				player.changePositionAfterCollisionWithEnemy(window);
			}

			window.display();
			if (window.hasFocus()) {
				//cout << "Playing..." << endl;
			}
			else {
				//cout << "Not Playing..." << endl;
			}
		}
	}
		return 0;
}
