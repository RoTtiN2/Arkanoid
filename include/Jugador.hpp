#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <SFML/Graphics.hpp>

class Jugador {
public:
    Jugador(sf::RenderWindow& window);

    void moverDerecha();
    void moverIzquierda();
    void dibujar(sf::RenderWindow& window);

    sf::Vector2f getPosition();

private:
    sf::RectangleShape paleta;
};

#endif // JUGADOR_HPP
