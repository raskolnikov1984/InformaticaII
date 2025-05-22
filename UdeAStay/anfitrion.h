#ifndef ANFITRION_H
#define ANFITRION_H
#include "usuario.h"

class Anfitrion : public Usuario
{
public:
    Anfitrion(const string& tipoUsario, const string& numeroDocumento, int antiguedad, float puntuacion);
    string tabla = "anfitrion.txt";
};

#endif // ANFITRION_H
