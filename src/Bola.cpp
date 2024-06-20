#include "bola.hpp"

Bola::Bola(sf::RenderWindow& window) {
    bola = sf::CircleShape(5.f);
    bola.setOrigin(2.5f, 2.5f);
    bola.setFillColor(sf::Color::Blue);
    bola.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    velDirBola = sf::Vector2f(-3, -3);
}

void Bola::mover() {
    bola.move(velDirBola);
}

void Bola::dibujar(sf::RenderWindow& window) {
    window.draw(bola);
}

sf::Vector2f Bola::getPosition() {
    return bola.getPosition();
}
