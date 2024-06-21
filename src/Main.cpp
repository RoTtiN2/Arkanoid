#include "Main.hpp"

struct Bloque Bloques[8][10];
int CantBloques = 56;
CircleShape Bola;
Vector2f VelDirBola(-3, -3);
RectangleShape Paleta;
bool EnColision = false;
bool Activo = true;
Font Fuente;
Text Texto;
int IdCV = 1;
int IdCH = 1;
SoundBuffer ParedSB, PaletaSB, BloqueSB;
Sound ParedS, PaletaS, BloqueS;
int Timer = 0;
Pastilla Pastilla;
int AuxPastilla;

int Main() {
    // Implementación del programa principal
    return 0;
}
