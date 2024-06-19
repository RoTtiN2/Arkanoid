#ifndef BOLA_HPP
#define BOLA_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "bloque.hpp"
#include "pastilla.hpp"

class Bola {
public:
    Bola(float radius);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    void move();
    void rebotarEnPared(float ventanaAncho);
    void rebotarEnTecho();
    void rebotarEnSuelo(float ventanaAlto, sf::Text& texto, bool& activo);
    void detectarColisionConPaleta(const sf::RectangleShape& paleta);
    void detectarColisionConBloques(Bloque bloques[8][10], int& cantBloques, Pastilla& pastilla);
    void draw(sf::RenderWindow& window);
    bool isColision() const;
    void setColision(bool colision);

private:
    sf::CircleShape bola;
    sf::Vector2f velDirBola;
    bool enColision;
    sf::Sound paredS, paletaS, bloqueS;
};

#endif // BOLA_HPP
