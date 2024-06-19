#ifndef BLOQUE_HPP
#define BLOQUE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

// Bloque de Vidrio
struct Bloque
{
    bool estado = true;
    RectangleShape bloque;
} bloques[8][10];

// Cantidad de Bloques Activos
extern int cantBloques;

// Bola
extern CircleShape bola;

// Direccion y Velocidad Bola
extern Vector2f velDirBola;

// Sonidos
extern SoundBuffer bloqueSB;
extern Sound bloqueS;

#endif // BLOQUE_HPP
