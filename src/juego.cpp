#include "juego.hpp"
#include <iostream>
#include <cstdlib>

void inicializarJuego() {
    // Inicializar bola
    bola = sf::CircleShape(5.f);
    bola.setOrigin(2.5f, 2.5f);
    bola.setFillColor(sf::Color::Blue);
    bola.setPosition(325, 250);

    // Inicializar paleta
    paleta = sf::RectangleShape(sf::Vector2f(60, 10));
    paleta.setOrigin(paleta.getSize().x / 2, paleta.getSize().y / 2);
    paleta.setFillColor(sf::Color::Green);
    paleta.setPosition(325, 480);

    // Cargar fuente y sonidos
    if (!fuente.loadFromFile("assets/fonts/ARCADE.TTF")) {
        std::cout << "Error al cargar la fuente." << std::endl;
    }
    texto.setFont(fuente);

    if (!paredSB.loadFromFile("assets/sounds/ReboteParedes.wav") || !paletaSB.loadFromFile("assets/sounds/RebotePaleta.wav") || !bloqueSB.loadFromFile("assets/sounds/ReboteLadrillo.wav")) {
        std::cout << "Error al cargar los sonidos." << std::endl;
    }
    paredS.setBuffer(paredSB);
    paletaS.setBuffer(paletaSB);
    bloqueS.setBuffer(bloqueSB);

    // Inicializar pastilla
    pastilla.pastilla = sf::RectangleShape(sf::Vector2f(30, 10));
    pastilla.pastilla.setFillColor(sf::Color::White);

    // Inicializar bloques de vidrio
    for (int i = 1; i < 8; i++) {
        idCV *= -1;
        for (int j = 1; j < 9; j++) {
            bloques[i][j].bloque = sf::RectangleShape(sf::Vector2f(65, 10));
            bloques[i][j].bloque.setPosition(j * 66, (i + 1) * 11);

            if (idCV == 1) {
                if (idCH == 1) {
                    bloques[i][j].bloque.setFillColor(sf::Color::Cyan);
                } else {
                    bloques[i][j].bloque.setFillColor(sf::Color::Green);
                }
            } else {
                if (idCH == 1) {
                    bloques[i][j].bloque.setFillColor(sf::Color::Yellow);
                } else {
                    bloques[i][j].bloque.setFillColor(sf::Color::Magenta);
                }
            }
            idCH *= -1;
        }
    }
}

void actualizarJuego() {
    // Lógica de actualización del juego
    // Rebote de la bola
    if (bola.getPosition().x >= 650 || bola.getPosition().x <= 0) {
        velDirBola.x *= -1;
        paredS.play();
    }
    if (bola.getPosition().y <= 0) {
        velDirBola.y *= -1;
        paredS.play();
    }
    if (bola.getPosition().y >= 500) {
        activo = false;
        texto.setString("Perdiste");
        texto.setPosition(200, 250);
    }

    // Movimiento de la paleta
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paleta.getPosition().x <= 650) {
        paleta.move(3.5, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paleta.getPosition().x >= 0) {
        paleta.move(-3.5, 0);
    }

    // Movimiento de la bola
    bola.move(velDirBola.x, velDirBola.y);

    // Colisiones
    if (!enColision) {
        // Colisión de la bola con la paleta
        if (paleta.getGlobalBounds().contains(bola.getPosition().x, bola.getPosition().y)) {
            if (paleta.getPosition().x - bola.getPosition().x >= 20) {
                velDirBola.x = -3;
            } else if (paleta.getPosition().x - bola.getPosition().x <= -20) {
                velDirBola.x = 3;
            } else {
                if (velDirBola.x > 0) {
                    velDirBola.x = 1.5;
                } else {
                    velDirBola.x = -1.5;
                }
            }
            velDirBola.y *= -1;
            enColision = true;
            paletaS.play();
        }

        // Colisión de la bola con los bloques
        for (int i = 1; i < 8; i++) {
            for (int j = 1; j < 9; j++) {
                if (bloques[i][j].estado && bloques[i][j].bloque.getGlobalBounds().contains(bola.getPosition().x, bola.getPosition().y)) {
                    velDirBola.y *= -1;
                    bloques[i][j].estado = false;
                    enColision = true;
                    cantBloques--;
                    bloqueS.play();

                    // Generar pastilla aleatoria
                    srand(time(NULL));
                    auxPastilla = 1 + rand() % 6;
                    if (auxPastilla == 1 && !pastilla.estado) {
                        pastilla.estado = true;
                        pastilla.pastilla.setPosition(bloques[i][j].bloque.getPosition().x, bloques[i][j].bloque.getPosition().y);
                    }
                }
            }
        }
    } else {
        enColision = false;
        if (paleta.getGlobalBounds().contains(bola.getPosition().x, bola.getPosition().y)) {
            enColision = true;
        }
        for (int i = 1; i < 8; i++) {
            for (int j = 1; j < 9; j++) {
                if (bloques[i][j].estado && bloques[i][j].bloque.getGlobalBounds().contains(bola.getPosition().x, bola.getPosition().y)) {
                    enColision = true;
                    break;
                }
            }
            if (enColision) {
                break;
            }
        }
    }

    // Movimiento de la pastilla
    if (pastilla.estado) {
        pastilla.pastilla.move(0, 2.5f);
    }

    // Comprobar el efecto de la pastilla
    if (timer >= 600) {
        paleta.setScale(1, 1);
    }

    // Comprobar si quedan bloques
    if (cantBloques <= 0) {
        activo = false;
        texto.setString("Ganaste");
        texto.setPosition(200, 250);
    }

    timer++;
}

void renderizarJuego(sf::RenderWindow &ventana) {
    ventana.clear();
    if (activo) {
        ventana.draw(bola);
        ventana.draw(paleta);

        for (int i = 1; i < 8; i++) {
            for (int j = 1; j < 9; j++) {
                if (bloques[i][j].estado) {
                    ventana.draw(bloques[i][j].bloque);
                }
            }
        }

        if (pastilla.estado) {
            ventana.draw(pastilla.pastilla);
        }
    } else {
        ventana.draw(texto);
    }
    ventana.display();
}

void manejarEventos(sf::RenderWindow &ventana) {
    sf::Event event;
    while (ventana.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            ventana.close();
        }
    }
}
