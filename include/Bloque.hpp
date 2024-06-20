#ifndef BLOQUE_HPP
#define BLOQUE_HPP

#include <SFML/Graphics.hpp>

class Bloque {
public:
    Bloque();

    void inicializar(float x, float y, bool estado, sf::Color color);
    void dibujar(sf::RenderWindow& window);
    bool colision(sf::Vector2f ballPosition);

private:
    bool estado;
    sf::RectangleShape bloque;
};

#endif // BLOQUE_HPP
