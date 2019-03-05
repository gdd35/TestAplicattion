#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>

#include "Jugador.h"
#include <SFML/Graphics.hpp>

class Score {

	public:
		Score() {}

		void mostrarPuntaje(RenderWindow &window ,Jugador &jugador) {
			if (!font.loadFromFile("Fonts/Gobold Uplow.ttf")) {
				cout << "ERROR" << endl;
			}
			puntaje.setFont(font);
			puntaje.setPosition(window.getSize().x / 2, 0);
			puntaje.setString(to_string(jugador._puntos));
			window.draw(puntaje);
		}

	private:
			Text puntaje;
			Font font;
};
