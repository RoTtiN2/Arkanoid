#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include "jugador.hpp"
#include "bloque.hpp"
#include "bola.hpp"
#include "pastilla.hpp"

using namespace std;
using namespace sf;

int main()
{
    // Ventana
    RenderWindow ventana(VideoMode(650, 500), "Arcanoid");
    ventana.setFramerateLimit(60);

    // Jugador
    Jugador jugador(ventana);

    // Bola
    Bola bola(ventana);

    // Bloques
    Bloque bloques[8][10];
    int idCV = 1, idCH = 1;
    for (int i = 0; i < 8; i++) {
        idCV *= -1;
        for (int j = 0; j < 10; j++) {
            sf::Color color;
            if (idCV == 1) {
                if (idCH == 1) {
                    color = sf::Color::Cyan;
                } else {
                    color = sf::Color::Green;
                }
            } else {
                if (idCH == 1) {
                    color = sf::Color::Yellow;
                } else {
                    color = sf::Color::Magenta;
                }
            }
            bloques[i][j].inicializar(j * 66, (i + 1) * 11, true, color);
            idCH *= -1;
        }
    }

    // Pastilla
    Pastilla pastilla;

    // Sonidos
    sf::SoundBuffer paredSB, paletaSB, bloqueSB;
    sf::Sound paredS, paletaS, bloqueS;

    if (!paredSB.loadFromFile("Sounds/ReboteParedes.wav") || !paletaSB.loadFromFile("Sounds/RebotePaleta.wav") || !bloqueSB.loadFromFile("Sounds/ReboteLadrillo.wav")) {
        cout << "Error al cargar los sonidos." << endl;
    }
    paredS.setBuffer(paredSB);
    paletaS.setBuffer(paletaSB);
    bloqueS.setBuffer(bloqueSB);

    // Fuente y Texto
    Font fuente;
    if (!fuente.loadFromFile("Fonts/ARCADE.TTF")) {
        cout << "Error al cargar la fuente." << endl;
    }
    Text texto;
    texto.setFont(fuente);

    // Timer/Contador
    int timer = 0;

    // Juego activo
    bool activo = true;

    while (ventana.isOpen()) {
        Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == Event::Closed) {
                ventana.close();
            }
        }

        timer++;

        if (activo) {
            // Movimiento de la bola
            bola.mover();

            // Colisiones Bola
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 10; j++) {
                    if (bloques[i][j].colision(bola.getPosition())) {
                        bola.rebotar();
                        bloques[i][j].estado = false;
                        bloqueS.play();

                        // Pastilla Aleatoria
                        srand(time(NULL));
                        int auxPastilla = 1 + rand() % 6; // Num Aleatorio 1-5
                        if (auxPastilla == 1 && !pastilla.getEstado()) {
                            pastilla.inicializar(bloques[i][j].getPosition().x, bloques[i][j].getPosition().y);
                        }
                    }
                }
            }

            // Rebote Bola
            if (bola.getPosition().x >= ventana.getSize().x || bola.getPosition().x <= 0) {
                bola.rebotar();
                paredS.play();
            }
            if (bola.getPosition().y <= 0) {
                bola.rebotar();
                paredS.play();
            }
            if (bola.getPosition().y >= ventana.getSize().y) {
                activo = false;
                texto.setString("Perdiste");
                texto.setPosition(200, ventana.getSize().y / 2);
            }

            // Movimiento de la paleta
            if (Keyboard::isKeyPressed(Keyboard::Right) && jugador.getPosition().x <= ventana.getSize().x) {
                jugador.moverDerecha();
            }
            if (Keyboard::isKeyPressed(Keyboard::Left) && jugador.getPosition().x >= 0) {
                jugador.moverIzquierda();
            }

            // Colision Bola-Paleta
            if (bola.getPosition().intersects(jugador.getPosition())) {
                bola.rebotar();
                paletaS.play();
            }

            // Movimiento Pastilla
            if (pastilla.getEstado()) {
                pastilla.mover();
                if (pastilla.colision(jugador.getPosition())) {
                    jugador.escalarPaleta();
                    pastilla.desactivar();
                    timer = 0;
                }
            }

            // Comprobar si quedan bloques
            if (cantBloques <= 0) {
                activo = false;
                texto.setString("Ganaste");
                texto.setPosition(200, ventana.getSize().y / 2);
            }

            // Comprobar efecto de la pastilla
            if (timer >= 600) {
                jugador.restaurarEscala();
            }
        }

        // Limpiar pantalla
        ventana.clear();

        // Dibujar elementos en pantalla
        jugador.dibujar(ventana);
        bola.dibujar(ventana);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 10; j++) {
                bloques[i][j].dibujar(ventana);
            }
        }
        if (pastilla.getEstado()) {
            pastilla.dibujar(ventana);
        } else {
            ventana.draw(texto);
        }

        // Mostrar pantalla
        ventana.display();
    }

    return 0;
}
