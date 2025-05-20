#include "anfitrion.h"

using namespace std;

Anfitrion::Anfitrion(const string& tipoUsuario, const string& numeroDocumento, int antiguedad, float puntuacion)
    : Usuario(tipoUsuario, numeroDocumento, antiguedad, puntuacion){}
