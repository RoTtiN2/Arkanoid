#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jugador.hpp"
#include "Bola.hpp"
#include "Bloque.hpp"
#include "Pastilla.hpp"

using namespace sf;

extern struct Bloque {
    bool Estado = true;
    RectangleShape Bloque;
} Bloques[8][10];

extern int CantBloques;
extern CircleShape Bola;
extern Vector2f VelDirBola;
extern RectangleShape Paleta;
extern bool EnColision;
extern bool Activo;
extern Font Fuente;
extern Text Texto;
extern int IdCV;
extern int IdCH;
extern SoundBuffer ParedSB;
extern SoundBuffer PaletaSB;
extern SoundBuffer BloqueSB;
extern Sound ParedS;
extern Sound PaletaS;
extern Sound BloqueS;
extern int Timer;
extern Pastilla Pastilla;
extern int AuxPastilla;

int Main();

#endif // MAIN_HPP
