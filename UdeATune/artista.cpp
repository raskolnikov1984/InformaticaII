#include "artista.h"

Artista::Artista() {

}

string Artista::getIdentificador() const
{
    return identificador;
}

void Artista::setIdentificador(const string &newIdentificador)
{
    identificador = newIdentificador;
}

int Artista::getEdad() const
{
    return edad;
}

void Artista::setEdad(int newEdad)
{
    edad = newEdad;
}

string Artista::getPais() const
{
    return pais;
}

void Artista::setPais(const string &newPais)
{
    pais = newPais;
}

int Artista::getSeguidores() const
{
    return seguidores;
}

void Artista::setSeguidores(int newSeguidores)
{
    seguidores = newSeguidores;
}

int Artista::getPosicionTendencias() const
{
    return posicionTendencias;
}

void Artista::setPosicionTendencias(int newPosicionTendencias)
{
    posicionTendencias = newPosicionTendencias;
}
