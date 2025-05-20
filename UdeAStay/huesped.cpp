#include "huesped.h"

using namespace std;

Huesped::Huesped(const string& tipoUsuario, const string& numeroDocumento, int antiguedad, float puntuacion)
    : Usuario(tipoUsuario, numeroDocumento, antiguedad, puntuacion){}
