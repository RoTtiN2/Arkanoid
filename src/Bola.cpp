#include "Bola.hpp"
#include <cstdlib>
#include <ctime>

Bola::Bola(float radius, sf::Vector2f position, sf::Color color) {
    bola = sf::CircleShape(radius);
    bola.setOrigin(radius, radius);
    bola.setFillColor(color);
    bola.setPosition(position);
    velDirBola = sf::Vector2f(-3, -3);
}

void Bola::move() {
    bola.move(velDirBola);
}

void Bola::checkBoundaryCollision(sf::RenderWindow &window, sf::Sound &paredSound) {
    if (bola.getPosition().x >= window.getSize().x || bola.getPosition().x <= 0) {
        velDirBola.x *= -1;
        paredSound.play();
    }
    if (bola.getPosition().y <= 0) {
        velDirBola.y *= -1;
        paredSound.play();
    }
}

void Bola::checkPaletaCollision(sf::RectangleShape &paleta, sf::Sound &paletaSound) {
    if (paleta.getGlobalBounds().intersects(bola.getGlobalBounds())) {
        float paletaCenterX = paleta.getPosition().x;
        float bolaCenterX = bola.getPosition().x;
        
        if (bolaCenterX < paletaCenterX) {
            velDirBola.x = -3;
        } else if (bolaCenterX > paletaCenterX) {
            velDirBola.x = 3;
        } else {
            velDirBola.x = 0;
        }
        
        velDirBola.y *= -1;
        paletaSound.play();
    }
}

void Bola::checkBloqueCollision(Bloque bloques[8][10], int &cantBloques, sf::Sound &bloqueSound, sf::RectangleShape &pastilla) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            if (bloques[i][j].estado && bloques[i][j].bloque.getGlobalBounds().intersects(bola.getGlobalBounds())) {
                velDirBola.y *= -1;
                bloques[i][j].estado = false;
                cantBloques--;
                bloqueSound.play();
                
                // Check for pastilla activation
                srand(time(NULL));
                int random = 1 + rand() % 6;
                if (random == 1 && !pastilla.estado) {
                    pastilla.estado = true;
                    pastilla.pastilla.setPosition(bloques[i][j].bloque.getPosition());
                }
            }
        }
    }
}

void Bola::draw(sf::RenderWindow &window) {
    window.draw(bola);
}

sf::Vector2f Bola::getPosition() {
    return bola.getPosition();
}
