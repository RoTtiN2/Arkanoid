#ifndef BOLA_HPP
#define BOLA_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bloque.hpp" // Asumiendo que Bloque.hpp define la estructura Bloque

class Bola {
private:
    sf::CircleShape bola;
    sf::Vector2f velDirBola;

public:
    Bola(float radius, sf::Vector2f position, sf::Color color);
    void move();
    void checkBoundaryCollision(sf::RenderWindow &window, sf::Sound &paredSound);
    void checkPaletaCollision(sf::RectangleShape &paleta, sf::Sound &paletaSound);
    void checkBloqueCollision(Bloque bloques[8][10], int &cantBloques, sf::Sound &bloqueSound, sf::RectangleShape &pastilla);
    void draw(sf::RenderWindow &window);
    sf::Vector2f getPosition();
};

#endif // BOLA_HPP
