#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

// Bloque de Vidrio
struct Bloque
{
    bool estado = true;
    RectangleShape bloque;
} bloques[8][10];

// Cantidad de Bloques Activos
int cantBloques = 56;

// Bola
CircleShape bola;

// Direccion y Velocidad Bola
Vector2f velDirBola(-3, -3);

// Sonidos
SoundBuffer bloqueSB;
Sound bloqueS;

int main()
{
    // Ventana
    RenderWindow ventana(VideoMode(650, 500), "Arcanoid");
    ventana.setFramerateLimit(60);

    // Bola
    bola = CircleShape(5.f);
    bola.setOrigin(2.5f, 2.5f);
    bola.setFillColor(Color::Blue);
    bola.setPosition(ventana.getSize().x / 2, ventana.getSize().y / 2);

    // Sonido de Bloque
    if (!bloqueSB.loadFromFile("Sounds/ReboteLadrillo.wav"))
    {
        cout << "Error al cargar el sonido de bloque." << endl;
    }
    bloqueS.setBuffer(bloqueSB);

    // Inicializacion de Bloques de Vidrio
    int idCV = 1, idCH = 1;
    for (int i = 1; i < 8; i++)
    {
        idCV *= -1;
        for (int j = 1; j < 9; j++)
        {
            // Tamaño Bloques
            bloques[i][j].bloque = RectangleShape(Vector2f(65, 10));
            // Posicion Bloques
            bloques[i][j].bloque.setPosition(j * 66, (i + 1) * 11);
            // Colores Bloques
            if (idCV == 1)
            { // Cian Verde
                if (idCH == 1)
                {
                    bloques[i][j].bloque.setFillColor(Color::Cyan);
                }
                else
                {
                    bloques[i][j].bloque.setFillColor(Color::Green);
                }
            }
            else
            { // Amarillo y Magenta
                if (idCH == 1)
                {
                    bloques[i][j].bloque.setFillColor(Color::Yellow);
                }
                else
                {
                    bloques[i][j].bloque.setFillColor(Color::Magenta);
                }
            }
            idCH *= -1;
        }
    }

    while (ventana.isOpen())
    {
        Event event;
        while (ventana.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                ventana.close();
            }
        }

        // Movimiento Bola
        bola.move(velDirBola.x, velDirBola.y);

        // Colisiones Bola Bloque Vidrio
        for (int i = 1; i < 8; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                if (bloques[i][j].estado && bloques[i][j].bloque.getGlobalBounds().intersects(bola.getGlobalBounds()))
                {
                    velDirBola.y *= -1;
                    bloques[i][j].estado = false;
                    cantBloques--;
                    bloqueS.play();
                }
            }
        }

        // Comprobar si quedan bloques
        if (cantBloques <= 0)
        {
            ventana.close();
        }

        // Limpiar Pantalla
        ventana.clear();

        // Dibujar Vitral de Bloques
        for (int i = 1; i < 8; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                if (bloques[i][j].estado)
                {
                    ventana.draw(bloques[i][j].bloque);
                }
            }
        }

        // Dibujar Bola
        ventana.draw(bola);

        // Mostrar Pantalla
        ventana.display();
    }

    return 0;
}
