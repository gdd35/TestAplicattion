#pragma region Headers

#include "pch.h"
#include "Jugador.h"
#include "Moneda.h"
#include "Background.h"
#include "Score.h"

#pragma endregion

#pragma region Bibliotecas

#include <iostream>
#include <SFML/Graphics.hpp>

#pragma endregion

using namespace std;
using namespace sf;

Vector2f SizeStartWindow(800,600);

int main()
{
	RenderWindow ventana(VideoMode(SizeStartWindow.x, SizeStartWindow.y), "Al fin me anduvo esta mierda concha la lora", sf::Style::Titlebar | sf::Style::Close);

	Jugador player("Sprites/movimiento_player.png");
	Moneda moneda("Sprites/moneda.png",ventana);
	Background background("Sprites/background.png",ventana);
	Score score;

	Clock clock;
	Time time;

	Event event;

#pragma region Declaraciones
	ventana.setFramerateLimit(20);
	ventana.setKeyRepeatEnabled(false);
#pragma endregion

	while (ventana.isOpen()) {

		while (ventana.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed:
				ventana.close();
				break;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) {
					ventana.close();
					return EXIT_SUCCESS;
				}
			}
		}

		time = clock.getElapsedTime();

		// Movimiento del jugador
		player.moverJugador(time,clock); 

		clock.restart().asMilliseconds();

		// Animacion de la moneda
		moneda.animacionMoneda();	

		ventana.clear();

#pragma region Orden al dibujar sprites

		//Hay que tener cuidado a la hora de poner los sprites, dado que estos se superponen, creo que el orden correcto seria background-> plataformas -> jugador -> enemigo -> moneda

#pragma endregion
		
		background.dibujarBackground(ventana);

		score.mostrarPuntaje(ventana,player);

		moneda.dibujarMoneda(ventana);

		player.dibujarJugador(ventana);

		player.actualizaJugador();

		moneda.actualizarMoneda();

		if (player.Collision(moneda, ventana)) {
			moneda.mSprite.setPosition(rand() % ventana.getSize().x, rand() % ventana.getSize().y);
		}
		
		ventana.display();
		if (ventana.hasFocus()) {
			//cout << "Jugando" << endl;
		}
		else {
			//cout << "No esta jugando" << endl;
		}
	}
	return 0;
}
