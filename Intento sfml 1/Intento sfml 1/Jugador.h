#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>

#include "Moneda.h"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Jugador {

public:

	float abajo, izquierda, derecha, arriba;
	int _puntos;
	Jugador() {}

	Jugador(string player)
	{
		puntos = 0;
		_puntos = 0;
		vida = 3;
		if (!pTexture.loadFromFile(player)) {
			cerr << "Error \n";
		}
		pTexture.setSmooth(true);
		pSprite.setScale(0.1, 0.1);
		pSprite.setTexture(pTexture);	

		// Posicion inicial dele sprite
		pSprite.setTextureRect(IntRect(1000,0,1000,1000)); 				
	}

	void dibujarJugador(RenderWindow &window) {
		window.draw(pSprite);
	}
#pragma region Entender Animacion Jugador

	// Bueno paso a explicar rapido, yo lo que hago es, como se que las animacion de cuando el personaje para abajo, pasa todo cuando y < 1000, lo unico que cambia es el valor de x, por eso
	// lo multiplico por un contador, para que se vaya desplazando a la derecha, y luego cuando llegaria al final, ese contador lo seteo en 0 asi vuelve a empezar
	// Igualmente si no quedo claro asi despues les explico mejor
#pragma endregion

	void moverJugador(Time time, Clock clock) {
		_time = time;
		_clock = clock;
		_time = clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			pSprite.move(0, movPlayer * _time.asMilliseconds() );
			pSprite.setTextureRect(IntRect(1000 * contadorMovimiento, 0, 1000, 1000)); 
			
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			pSprite.move(0, -movPlayer * _time.asMilliseconds() );
			pSprite.setTextureRect(IntRect(1000 * contadorMovimiento, 1000, 1000, 1000));
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			pSprite.move(movPlayer *_time.asMilliseconds() , 0);
			pSprite.setTextureRect(IntRect(1000 * contadorMovimiento, 2000, 1000, 1000));
			
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			pSprite.move(-movPlayer * _time.asMilliseconds() , 0);
			pSprite.setTextureRect(IntRect(1000 * contadorMovimiento, 3000, 1000, 1000));
			
			
		}
		contadorMovimiento++;

		if (contadorMovimiento == 3) {
			contadorMovimiento = 0;
		}	
		_clock.restart().asMilliseconds();	
	}

	void actualizaJugador() {
		abajo = pSprite.getPosition().y + (pSprite.getGlobalBounds().height*0.90);
		izquierda = pSprite.getPosition().x + (pSprite.getGlobalBounds().width*0.25);
		derecha = pSprite.getPosition().x + (pSprite.getGlobalBounds().width *0.75);
		arriba = pSprite.getPosition().y + (pSprite.getGlobalBounds().height*0.25);
	}
			// pSprite.getPosition().x + (pSprite.getGlobalBounds().width / 4) esto me da la parte izquierda del personaje o lo mismo que multiplicar el tamaño por 0.25
			// pSprite.getPosition().x + (pSprite.getGlobalBounds().width *0.75 esto me da la parte derecha del personaje 
			// pSprite.getPosition().y + (pSprite.getGlobalBounds().height*0.25) esto me da la parte de arriba del personaje (a partir del casco)
			// pSprite.getPosition().y + (pSprite.getGlobalBounds().height*0.90) esto me da la parte de abajo del personaje

	bool Collision(Moneda moneda , RenderWindow &window) {

		if (derecha < moneda.izquierda  || izquierda > moneda.derecha ||
			arriba > moneda.abajo || abajo < moneda.arriba) {
			return false;
		}
		else {
			puntos++;
			_puntos = puntos;
			return true;
		}
	}
private: 
	Texture pTexture;
	Sprite	pSprite;
	Time _time;
	Clock _clock;

	int vida;
	int puntos;
	int contadorMovimiento = 0;
	float movPlayer = 0.099;

};
