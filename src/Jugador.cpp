#include "Jugador.hpp"

Jugador::Jugador(sf::Vector2f size, sf::Vector2f position, sf::Color color) {
    paleta.setSize(size);
    paleta.setOrigin(size.x / 2, size.y / 2);
    paleta.setFillColor(color);
    paleta.setPosition(position);
}

void Jugador::moveLeft(float deltaTime) {
    paleta.move(-3.5f * deltaTime, 0);
}

void Jugador::moveRight(float deltaTime) {
    paleta.move(3.5f * deltaTime, 0);
}

void Jugador::draw(sf::RenderWindow &window) {
    window.draw(paleta);
}

sf::Vector2f Jugador::getPosition() {
    return paleta.getPosition();
}

sf::FloatRect Jugador::getGlobalBounds() {
    return paleta.getGlobalBounds();
}
