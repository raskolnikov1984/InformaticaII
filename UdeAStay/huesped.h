#ifndef HUESPED_H
#define HUESPED_H
#include "usuario.h"
#include "reserva.h"


class Huesped : public Usuario
{
public:
    Huesped(const string& tipoUsario, const string& numeroDocumento, int antiguedad, float puntuacion);
    string tabla = "huespedes.txt";
};

#endif // HUESPED_H
