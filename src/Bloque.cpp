#include "bloque.hpp"

Bloque::Bloque() {}

void Bloque::inicializar(float x, float y, bool estado, sf::Color color) {
    this->estado = estado;
    bloque = sf::RectangleShape(sf::Vector2f(65, 10));
    bloque.setPosition(x, y);
    bloque.setFillColor(color);
}

void Bloque::dibujar(sf::RenderWindow& window) {
    if (estado) {
        window.draw(bloque);
    }
}

bool Bloque::colision(sf::Vector2f ballPosition) {
    return estado && bloque.getGlobalBounds().contains(ballPosition);
}
