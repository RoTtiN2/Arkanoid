#ifndef ARCANOID_HPP
#define ARCANOID_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

// Estructura del Bloque de Vidrio
struct Bloque
{
    bool estado = true;  // Estado activo/inactivo del bloque
    RectangleShape bloque;  // Forma rectangular del bloque
};

// Estructura de la Pastilla
struct Pastilla
{
    bool estado = false;  // Estado activo/inactivo de la pastilla
    RectangleShape pastilla;  // Forma rectangular de la pastilla
};

// Variables globales
extern Bloque bloques[8][10];  // Matriz de bloques de vidrio
extern Pastilla pastilla;  // Pastilla presente en el juego
extern int cantBloques;  // Cantidad de bloques activos

extern CircleShape bola;  // Bola del juego
extern Vector2f velDirBola;  // Dirección y velocidad de la bola
extern RectangleShape paleta;  // Paleta del jugador
extern bool enColision;  // Indicador de colisión
extern bool activo;  // Estado del juego
extern Font fuente;  // Fuente utilizada para texto
extern Text texto;  // Texto mostrado en pantalla
extern int timer;  // Contador/tiempo del juego

// Funciones y métodos
void inicializarBloques();
void manejarColisiones(RenderWindow &ventana);
void manejarMovimientos(RenderWindow &ventana);

#endif // ARCANOID_HPP
