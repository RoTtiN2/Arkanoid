#ifndef BOLA_HPP
#define BOLA_HPP

#include <SFML/Graphics.hpp>

class Bola {
public:
    Bola(sf::RenderWindow& window);

    void mover();
    void dibujar(sf::RenderWindow& window);

    sf::Vector2f getPosition();

private:
    sf::CircleShape bola;
    sf::Vector2f velDirBola;
};

#endif // BOLA_HPP
