#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Jugador {

public:
	Jugador() {}

	Jugador(string player)
	{

		if (!pTexture.loadFromFile(player)) {
			cerr << "Error \n";
		}
		pTexture.setSmooth(true);
		pSprite.setTexture(pTexture);
		pSprite.setTextureRect(IntRect(1000,0,1000,1000)); // Posicion inicial dele sprite
		pSprite.setScale(0.1, 0.1); // Seteo escala para que quede mas o menos proporcional (esto esta hecho a ojo)
	}

	void dibujarJugador(RenderWindow &window) {
		window.draw(pSprite);
	}
	void actualizarJugador() {

#pragma region Entender Animacion Jugador

		// Bueno paso a explicar rapido, yo lo que hago es, como se que las animacion de cuando el personaje para abajo, pasa todo cuando y < 1000, lo unico que cambia es el valor de x, por eso
		// lo multiplico por un contador, para que se vaya desplazando a la derecha, y luego cuando llegaria al final, ese contador lo seteo en 0 asi vuelve a empezar
		// Igualmente si no quedo claro asi despues les explico mejor
#pragma endregion


		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			pSprite.move(0, movPlayer);
			pSprite.setTextureRect(IntRect(1000 * contadorMovimiento, 0, 1000, 1000)); 
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			pSprite.move(0, -movPlayer);
			pSprite.setTextureRect(IntRect(1000 * contadorMovimiento, 1000, 1000, 1000));
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			pSprite.move(movPlayer, 0);
			pSprite.setTextureRect(IntRect(1000 * contadorMovimiento, 2000, 1000, 1000));
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			pSprite.move(-movPlayer, 0);
			pSprite.setTextureRect(IntRect(1000 * contadorMovimiento, 3000, 1000, 1000));
		}
		contadorMovimiento++;

		if (contadorMovimiento == 3) {
			contadorMovimiento = 0;
		}
	}
private:
	Texture pTexture;
	Sprite	pSprite;

	float movimientoJugador = 10;
	int contadorMovimiento = 0;
	float movPlayer = 2;

};
