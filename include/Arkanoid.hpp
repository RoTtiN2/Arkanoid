#ifndef ARCANOID_HPP
#define ARCANOID_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>

class Jugador {
public:
    Jugador(sf::RenderWindow& ventana);
    void moverDerecha();
    void moverIzquierda();
    void dibujar(sf::RenderWindow& ventana);
    sf::FloatRect getPosition() const;

private:
    sf::RectangleShape forma;
    float velocidad;
};

class Bola {
public:
    Bola(sf::RenderWindow& ventana);
    void mover();
    void rebotar();
    void dibujar(sf::RenderWindow& ventana);
    sf::FloatRect getPosition() const;

private:
    sf::CircleShape forma;
    sf::Vector2f velocidad;
};

class Bloque {
public:
    Bloque();
    void inicializar(float x, float y, bool estado, sf::Color color);
    void dibujar(sf::RenderWindow& ventana);
    bool colision(const sf::FloatRect& objeto) const;
    sf::Vector2f getPosition() const;
    bool getEstado() const;

public:
    bool estado;

private:
    sf::RectangleShape forma;
};

class Pastilla {
public:
    Pastilla();
    void inicializar(float x, float y);
    void mover();
    void dibujar(sf::RenderWindow& ventana);
    bool colision(const sf::FloatRect& objeto) const;
    void desactivar();
    bool getEstado() const;

private:
    sf::RectangleShape forma;
    sf::Vector2f velocidad;
    bool activo;
};

class Arcanoid {
public:
    Arcanoid();
    void ejecutar();

private:
    sf::RenderWindow ventana;
    Jugador jugador;
    Bola bola;
    Bloque bloques[8][10];
    Pastilla pastilla;
    sf::SoundBuffer paredSB, paletaSB, bloqueSB;
    sf::Sound paredS, paletaS, bloqueS;
    sf::Font fuente;
    sf::Text texto;
    int timer;
    bool activo;

    void inicializarVentana();
    void inicializarJuego();
    void manejarEventos();
    void actualizar();
    void dibujar();
    bool verificarBloquesRestantes();
};

#endif // ARCANOID_HPP
