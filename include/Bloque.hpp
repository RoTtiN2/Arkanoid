#ifndef BLOQUE_HPP
#define BLOQUE_HPP

#include <SFML/Graphics.hpp>

class Bloque {
private:
    sf::RectangleShape bloque;
    bool estado;

public:
    Bloque();
    void inicializar(float x, float y, bool estado, sf::Color color);
    bool colision(sf::FloatRect bolaPos);
    void dibujar(sf::RenderWindow& ventana);
    sf::Vector2f getPosition();
};

#endif // BLOQUE_HPP
