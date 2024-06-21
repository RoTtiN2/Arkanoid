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

#endif // PASTILLA_HPP
