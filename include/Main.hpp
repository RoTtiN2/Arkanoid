#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include "Arkanoid_completo.hpp"

// Implementación de las variables globales
Bloque bloques[8][10];
Pastilla pastilla;
int auxPastilla;
int cantBloques = 56;
sf::CircleShape bola;
sf::Vector2f velDirBola(-3, -3);
sf::RectangleShape paleta;
bool enColision = false;
bool activo = true;
sf::Font fuente;
sf::Text texto;
int idCV = 1, idCH = 1;
sf::SoundBuffer paredSB, paletaSB, bloqueSB;
sf::Sound paredS, paletaS, bloqueS;
int timer = 0;

#endif // MAIN_HPP
