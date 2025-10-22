#include "cancion.h"

string Cancion::getIdentificador() const
{
    return identificador;
}

void Cancion::setIdentificador(const string &newIdentificador)
{
    identificador = newIdentificador;
}

string Cancion::getNombre() const
{
    return nombre;
}

void Cancion::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

string Cancion::getAlbum () const
{
    return album ;
}

void Cancion::setAlbum(const string &newAlbum )
{
    nombre = newAlbum ;
}
string Cancion::getDuracion() const
{
    return duracion;
}

void Cancion::setDuracion(const string &newDuracion)
{
    duracion = newDuracion;
}

string Cancion::getUbicacion() const
{
    return ubicacion;
}

void Cancion::setUbicacion(const string &newUbicacion)
{
    ubicacion = newUbicacion;
}

string Cancion::getCreditos() const
{
    return creditos;
}

void Cancion::setCreditos(const string &newCreditos)
{
    creditos = newCreditos;
}

int Cancion::getReproducciones() const
{
    return reproducciones;
}

void Cancion::setReproducciones(int newReproducciones)
{
    reproducciones = newReproducciones;
}
