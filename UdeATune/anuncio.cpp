#include "anuncio.h"


Anuncio::Anuncio() : mensaje(""), categoria(' '), prioridad(0) {

}
Anuncio::Anuncio(const string &mensaje, char categoria, int prioridad) : mensaje(mensaje),
    categoria(categoria),
    prioridad(prioridad)
{}

string Anuncio::getMensaje() const
{
    return mensaje;
}

void Anuncio::setMensaje(const string &newMensaje)
{
    mensaje = newMensaje;
}

char Anuncio::getCategoria() const
{
    return categoria;
}

void Anuncio::setCategoria(char newCategoria)
{
    categoria = newCategoria;
}

int Anuncio::getPrioridad() const
{
    return prioridad;
}

void Anuncio::setPrioridad(int newPrioridad)
{
    prioridad = newPrioridad;
}
