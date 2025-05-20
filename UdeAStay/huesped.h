#ifndef HUESPED_H
#define HUESPED_H
#include "usuario.h"

class Huesped : public Usuario
{
public:
    Huesped(const string& tipoUsario, const string& numeroDocumento, int antiguedad, float puntuacion);
};

#endif // HUESPED_H
