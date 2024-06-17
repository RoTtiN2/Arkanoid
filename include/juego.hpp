#ifndef JUEGO_HPP
#define JUEGO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Bloque de Vidrio
struct Bloque {
    bool estado;
    sf::RectangleShape bloque;
};

// Pastilla
struct Pastilla {
    bool estado;
    sf::RectangleShape pastilla;
};

extern Bloque bloques[8][10];
extern Pastilla pastilla;
extern int auxPastilla;
extern int cantBloques;
extern sf::CircleShape bola;
extern sf::Vector2f velDirBola;
extern sf::RectangleShape paleta;
extern bool enColision;
extern bool activo;
extern sf::Font fuente;
extern sf::Text texto;
extern int idCV, idCH;
extern sf::SoundBuffer paredSB, paletaSB, bloqueSB;
extern sf::Sound paredS, paletaS, bloqueS;
extern int timer;

void inicializarJuego();
void actualizarJuego();
void renderizarJuego(sf::RenderWindow &ventana);
void manejarEventos(sf::RenderWindow &ventana);

#endif // JUEGO_HPP
