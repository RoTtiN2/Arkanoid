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

Bloque::Bloque() {
    estado = true;
}

void Bloque::inicializar(float x, float y, bool estado, sf::Color color) {
    bloque.setSize(sf::Vector2f(65, 10));
    bloque.setFillColor(color);
    bloque.setPosition(x, y);
    this->estado = estado;
}

bool Bloque::colision(sf::FloatRect bolaPos) {
    if (estado && bloque.getGlobalBounds().intersects(bolaPos)) {
        estado = false;
        return true;
    }
    return false;
}

void Bloque::dibujar(sf::RenderWindow& ventana) {
    if (estado) {
        ventana.draw(bloque);
    }
}

sf::Vector2f Bloque::getPosition() {
    return bloque.getPosition();
}


#endif // BLOQUE_HPP
