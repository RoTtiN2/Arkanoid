#include "Bola.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

Bola::Bola(float radius) : velDirBola(-3, -3), enColision(false) {
    bola = CircleShape(radius);
    bola.setOrigin(radius / 2, radius / 2);
    bola.setFillColor(Color::Blue);
}

void Bola::setPosition(float x, float y) {
    bola.setPosition(x, y);
}

Vector2f Bola::getPosition() const {
    return bola.getPosition();
}

void Bola::move() {
    bola.move(velDirBola.x, velDirBola.y);
}

void Bola::rebotarEnPared(float ventanaAncho) {
    if (bola.getPosition().x >= ventanaAncho || bola.getPosition().x <= 0) {
        velDirBola.x *= -1;
        paredS.play();
    }
}

void Bola::rebotarEnTecho() {
    if (bola.getPosition().y <= 0) {
        velDirBola.y *= -1;
        paredS.play();
    }
}

void Bola::detectarColisionConPaleta(const RectangleShape& paleta) {
    if (paleta.getGlobalBounds().contains(bola.getPosition().x, bola.getPosition().y)) {
        if (paleta.getPosition().x - bola.getPosition().x >= 20) {
            velDirBola.x = -3;
        } else if (paleta.getPosition().x - bola.getPosition().x <= -20) {
            velDirBola.x = 3;
        } else {
            velDirBola.x = (velDirBola.x > 0) ? 1.5 : -1.5;
        }
        velDirBola.y *= -1;
        enColision = true;
        paletaS.play();
    }
}

void Bola::detectarColisionConBloques(Bloque bloques[8][10], int& cantBloques, Pastilla& pastilla) {
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 9; j++) {
            if (bloques[i][j].estado && bloques[i][j].bloque.getGlobalBounds().contains(bola.getPosition().x, bola.getPosition().y)) {
                velDirBola.y *= -1;
                bloques[i][j].estado = false;
                enColision = true;
                cantBloques--;
                bloqueS.play();
                srand(time(NULL));
                int auxPastilla = 1 + rand() % 6;
                if (auxPastilla == 1 && !pastilla.estado) {
                    pastilla.estado = true;
                    pastilla.pastilla.setPosition(bloques[i][j].bloque.getPosition().x, bloques[i][j].bloque.getPosition().y);
                }
            }
        }
    }
}

void Bola::draw(RenderWindow& window) {
    window.draw(bola);
}

bool Bola::isColision() const {
    return enColision;
}

void Bola::setColision(bool colision) {
    enColision = colision;
}

void Bola::rebotarEnSuelo(float ventanaAlto, Text& texto, bool& activo) {
    if (bola.getPosition().y >= ventanaAlto) {
        activo = false;
        texto.setString("Perdiste");
        texto.setPosition(200, ventanaAlto / 2);
    }
}
