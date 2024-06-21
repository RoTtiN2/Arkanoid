#ifndef PUNTUAJE_HPP
#define PUNTUAJE_HPP

#include <SFML/Graphics.hpp>

class Puntuaje {
private:
    int puntuacion;
    sf::Text textoPuntuacion;
    sf::Font fuente;

public:
    Puntuaje();
    void incrementarPuntuacion(int puntos);
    void reiniciarPuntuacion();
    void draw(sf::RenderWindow &window);
};

#endif // PUNTUAJE_HPP
