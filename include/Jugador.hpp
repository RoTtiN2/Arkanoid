#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <SFML/Graphics.hpp>

class Jugador {
private:
    sf::RectangleShape paleta;

public:
    Jugador(sf::Vector2f size, sf::Vector2f position, sf::Color color);
    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);
    void draw(sf::RenderWindow &window);
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
};

#endif // JUGADOR_HPP
