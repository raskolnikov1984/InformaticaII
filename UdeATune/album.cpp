#include "album.h"

string Album::getIdentificador() const
{
    return identificador;
}

void Album::setIdentificador(const string &newIdentificador)
{
    identificador = newIdentificador;
}

string Album::getArtista() const
{
    return artista;
}

void Album::setArtista(const string &newArtista)
{
    artista = newArtista;
}

string Album::getGenero() const
{
    return genero;
}

void Album::setGenero(const string &newGenero)
{
    genero = newGenero;
}

string Album::getFechaLanzamiento() const
{
    return fechaLanzamiento;
}

void Album::setFechaLanzamiento(const string &newFechaLanzamiento)
{
    fechaLanzamiento = newFechaLanzamiento;
}

string Album::getDuracion() const
{
    return duracion;
}

void Album::setDuracion(const string &newDuracion)
{
    duracion = newDuracion;
}

string Album::getNombre() const
{
    return nombre;
}

void Album::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

string Album::getSello() const
{
    return sello;
}

void Album::setSello(const string &newSello)
{
    sello = newSello;
}

string Album::getPuntuacion() const
{
    return puntuacion;
}

void Album::setPuntuacion(const string &newPuntuacion)
{
    puntuacion = newPuntuacion;
}
