#include "usuario.h"
#include <stdexcept>

using namespace  std;

Usuario::Usuario()
    : tipoUsuario("huesped"), numeroDocumento(""), antiguedad(0), puntuacion(0.0f), password("") {}

Usuario::Usuario(const string& tipoUsuario, const string& numeroDocumento, int antiguedad, float puntuacion)
    : tipoUsuario(" "), numeroDocumento(" "), antiguedad(0), puntuacion(0), password(""){
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

void Usuario::setTipoUsuario(const string &newTipoUsuario)
{
    tipoUsuario = newTipoUsuario;
}

void Usuario::setNumeroDocumento(const string &newNumeroDocumento)
{
    numeroDocumento = newNumeroDocumento;
}

void Usuario::setAntiguedad(int newAntiguedad)
{
    antiguedad = newAntiguedad;
}

void Usuario::setPuntuacion(float newPuntuacion)
{
    puntuacion = newPuntuacion;
}

void Usuario::setPassword(const string &newPassword)
{
    password = newPassword;
};
