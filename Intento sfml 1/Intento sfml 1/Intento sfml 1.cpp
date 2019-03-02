// Intento sfml 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#pragma region Headers
#include "pch.h"
#include "Jugador.h"
#include "Moneda.h"
#include "Background.h"
#pragma endregion
#pragma region Bibliotecas
#include <iostream>
#include <SFML/Graphics.hpp>
#pragma endregion

using namespace std;
using namespace sf;

Vector2i SizeStartWindow(800,600);

int main()
{

	
	RenderWindow ventana(VideoMode(SizeStartWindow.x, SizeStartWindow.y), "Al fin me anduvo esta mierda concha la lora");

	Jugador player("Sprites/movimiento_player.png");
	Moneda moneda("Sprites/moneda.png");
	Background background("Sprites/background.png",ventana);

	Event event;

#pragma region Declaraciones
	ventana.setFramerateLimit(15);
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

		player.actualizarJugador(); // Movimiento del jugador, esto despues hay que ponerlo mas prolijo

		moneda.actualizarMoneda();	// Animacion de la moneda

		ventana.clear();

#pragma region Orden al dibujar sprites

		//Hay que tener cuidado a la hora de poner los sprites, dado que estos se superponen, creo que el orden correcto seria background-> plataformas -> jugador -> enemigo -> moneda

#pragma endregion

		background.dibujarBackground(ventana);

		player.dibujarJugador(ventana);

		moneda.dibujarMoneda(ventana);

		ventana.display();

	}
}
