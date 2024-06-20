#include "pastilla.hpp"
#include <cstdlib>
#include <ctime>

Pastilla::Pastilla() {}

void Pastilla::inicializar(float x, float y) {
    estado = true;
    pastilla = sf::RectangleShape(sf::Vector2f(30, 10));
    pastilla.setFillColor(sf::Color::White);
    pastilla.setPosition(x, y);
}

void Pastilla::mover() {
    pastilla.move(0, 2.5f);
}

void Pastilla::dibujar(sf::RenderWindow& window) {
    if (estado) {
        window.draw(pastilla);
    }
}

bool Pastilla::colision(sf::FloatRect objectBounds) {
    return estado && pastilla.getGlobalBounds().intersects(objectBounds);
}

bool Pastilla::getEstado() {
    return estado;
}
