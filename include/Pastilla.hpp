#ifndef PASTILLA_HPP
#define PASTILLA_HPP

#include <SFML/Graphics.hpp>

class Pastilla {
private:
    sf::RectangleShape pastilla;
    bool estado;

public:
    Pastilla();
    void inicializar(float x, float y);
    void mover();
    void dibujar(sf::RenderWindow& ventana);
    bool colision(sf::FloatRect jugadorPos);
    bool getEstado();
    void desactivar();
};


Pastilla::Pastilla() {
    estado = false;
}

void Pastilla::inicializar(float x, float y) {
    pastilla.setSize(sf::Vector2f(30, 10));
    pastilla.setFillColor(sf::Color::White);
    pastilla.setPosition(x, y);
    estado = true;
}

void Pastilla::mover() {
    pastilla.move(0, 2.5f);
}

void Pastilla::dibujar(sf::RenderWindow& ventana) {
    if (estado) {
        ventana.draw(pastilla);
    }
}

bool Pastilla::colision(sf::FloatRect jugadorPos) {
    if (estado && pastilla.getGlobalBounds().intersects(jugadorPos)) {
        estado = false;
        return true;
    }
    return false;
}

bool Pastilla::getEstado() {
    return estado;
}

void Pastilla::desactivar() {
    estado = false;
}

#endif // PASTILLA_HPP
