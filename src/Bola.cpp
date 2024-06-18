#include <SFML/Graphics.hpp>

int main()
{
    // Crear una ventana de SFML
    sf::RenderWindow window(sf::VideoMode(650, 500), "SFML works!");

    // Crear una forma circular de SFML
    sf::CircleShape shape(5.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Verificar si se ha cerrado la ventana
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar la forma en la ventana
        window.draw(shape);

        // Mostrar la ventana
        window.display();
    }

    return 0;
}