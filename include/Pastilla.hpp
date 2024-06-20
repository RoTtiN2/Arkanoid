#ifndef PASTILLA_HPP
#define PASTILLA_HPP

#include <SFML/Graphics.hpp>

class Pastilla {
public:
    Pastilla();

    void inicializar(float x, float y);
    void mover();
    void dibujar(sf::RenderWindow& window);
    bool colision(sf::FloatRect objectBounds);
    bool getEstado();

private:
    bool estado;
    sf::RectangleShape pastilla;
};

#endif // PASTILLA_HPP
