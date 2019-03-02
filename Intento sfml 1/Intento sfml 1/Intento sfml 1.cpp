// Intento sfml 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Jugador.h"
#include "Moneda.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int a = 0;
int contadorMovimiento = 0;

int main()
{
	RenderWindow ventana(VideoMode(800, 600), "Al fin me anduvo esta mierda concha la lora");

	Event event;

#pragma region Declaraciones
	ventana.setFramerateLimit(10);
	ventana.setKeyRepeatEnabled(false);
#pragma endregion


	

	Jugador player("Sprites/movimiento_player.png");
	Moneda moneda("Sprites/moneda.png");

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

		player.actualizarJugador();

		moneda.actualizarMoneda();	

		ventana.clear();

		player.dibujarJugador(ventana);

		moneda.dibujarMoneda(ventana);

		ventana.display();
	}
}
