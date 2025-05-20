#include "usuario.h"
#include <stdexcept>

using namespace  std;

Usuario::Usuario(const string& tipoUsuario, const string& numeroDocumento, int antiguedad, float puntuacion)
    : tipoUsuario(tipoUsuario), numeroDocumento(numeroDocumento), antiguedad(antiguedad), puntuacion(puntuacion) {
    if(puntuacion < 0 || puntuacion > 5.0){
        throw invalid_argument("La puntuacion debe esta entre 0 y 5.0");
    }

    if(tipoUsuario != "huesped" && tipoUsuario != "anfitrion"){
        throw invalid_argument("El Tipo de Usuario debe ser (huesped, anfitrion)");
    }
}

string Usuario::getNumeroDocumento() const {
    return this->numeroDocumento;
}

int Usuario::getAntiguedad() const {
    return this->antiguedad;
}

float Usuario::getPuntuacion() const {
    return this->puntuacion;
}

string Usuario::getTipoUsuario() const {
    return this->tipoUsuario;
}
