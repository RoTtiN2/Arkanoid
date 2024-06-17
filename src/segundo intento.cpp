#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include<string>

using namespace std;
using namespace sf;

//Bola
CircleShape bola;
//Dreccion y velocidad Bola
Vector2f velDirBola(-3,-3);

int main(){
    //ventana
    RenderWindow ventana(VideoMode(650,500),"arkanoid");
    ventana.setFramerateLimit(60);
    //bola
    bola = CircleShape(5.f);
    bola.setOrigin(2.5f,2.5f);
    bola.setFillColor(Color::Blue);
    bola.setPosition(ventana.getSize().x/2,ventana.getSize().y/2);
    
    while (ventana.isOpen()){
        Event event;
        while (ventana.pollEvent(event)){
            if(event.type == Event::Closed){
                ventana.close();
            }
        }
        //Rebote Bola x
        if(bola.getPosition().x >= ventana.getSize().x || bola.getPosition().x <= 0){
            //cambios de direccion en X
            velDirBola.x*=-1;
        } 
        //Rebote Bola y
        if(bola.getPosition().y >= ventana.getSize().y || bola.getPosition().y <= 0){
            //cambios de direccion en X
            velDirBola.y*=-1;
        } 
        //Movimiento bola 
        bola.move(velDirBola.x,velDirBola.y);
        //Limpiar pantalla 
        ventana.clear();
        //Dibujar pantalla
        ventana.draw(bola);
        //Mostrar pantalla

        ventana.display();
    }
    
    return 0;
}