#include "jugador.hpp"

Jugador::Jugador(sf::RenderWindow& window) {
    paleta = sf::RectangleShape(sf::Vector2f(60, 10));
    paleta.setOrigin(paleta.getSize().x / 2, paleta.getSize().y / 2);
    paleta.setFillColor(sf::Color::Green);
    paleta.setPosition(window.getSize().x / 2, window.getSize().y - 20);
}

void Jugador::moverDerecha() {
    paleta.move(3.5, 0);
}

void Jugador::moverIzquierda() {
    paleta.move(-3.5, 0);
}

void Jugador::dibujar(sf::RenderWindow& window) {
    window.draw(paleta);
}

sf::Vector2f Jugador::getPosition() {
    return paleta.getPosition();
}
