#pragma once
#include <Pastilla.hpp>
#include <list>

using namespace std;

class Juego
{
private:
    list<Pastilla> pastillas;
public:
    Juego() {
        for (size_t i = 0; i < 20; i++)
        {
            pastillas.emplace_back(Pastilla());
        }
        
    }
    ~Juego() {}
    void Ejecutar(){
        while (this->EstaEjecutandose())
        {
            // Actualizar objetos
            for (auto &&pastilla : pastillas)
            {
                pastilla.colision();
            }

            // Dibujar Objetos
            for (auto &&pastilla : pastillas)
            {
                pastilla.dibujar();
            }
            
        }
        
    }

    bool EstaEjecutandose(){
        return true;
    }
};