#ifndef PASTILLA_HPP
#define PASTILLA_HPP

#include <SFML/Graphics.hpp>

class Pastilla {
public:
    // Constructor para inicializar la pastilla
    Pastilla();

    // Método para mover la pastilla hacia abajo
    void mover();

    // Método para establecer la posición de la pastilla
    void setPosition(float x, float y);

    // Método para verificar la colisión con la paleta
    bool detectarColisionConPaleta(const sf::RectangleShape& paleta, int& timer);

    // Método para dibujar la pastilla en la ventana
    void draw(sf::RenderWindow& window);

    // Método para establecer el estado de la pastilla
    void setEstado(bool nuevoEstado);

    // Método para obtener el estado de la pastilla
    bool getEstado() const;

private:
    bool estado;
    sf::RectangleShape pastilla;
};

#endif // PASTILLA_HPP
