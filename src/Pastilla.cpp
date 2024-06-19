#include "pastilla.hpp"

// Constructor para inicializar la pastilla
Pastilla::Pastilla() {
    estado = false;
    pastilla.setSize(sf::Vector2f(30, 10));
    pastilla.setFillColor(sf::Color::White);
}

// Método para mover la pastilla hacia abajo
void Pastilla::mover() {
    if (estado) {
        pastilla.move(0, 2.5f);
    }
}

// Método para establecer la posición de la pastilla
void Pastilla::setPosition(float x, float y) {
    pastilla.setPosition(x, y);
}

// Método para verificar la colisión con la paleta
bool Pastilla::detectarColisionConPaleta(const sf::RectangleShape& paleta, int& timer) {
    if (estado && paleta.getGlobalBounds().contains(pastilla.getPosition().x, pastilla.getPosition().y)) {
        estado = false;
        timer = 0;
        return true;
    }
    return false;
}

// Método para dibujar la pastilla en la ventana
void Pastilla::draw(sf::RenderWindow& window) {
    if (estado) {
        window.draw(pastilla);
    }
}

// Método para establecer el estado de la pastilla
void Pastilla::setEstado(bool nuevoEstado) {
    estado = nuevoEstado;
}

// Método para obtener el estado de la pastilla
bool Pastilla::getEstado() const {
    return estado;
}
