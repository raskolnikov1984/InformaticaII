#include "usuario.h"

QString Usuario::getNombre() const
{
    return nombre;
}

void Usuario::setNombre(const QString &newNombre)
{
    nombre = newNombre;
}

QString Usuario::getCorreo() const
{
    return correo;
}

void Usuario::setCorreo(const QString &newCorreo)
{
    correo = newCorreo;
}

QString Usuario::getTelefono() const
{
    return telefono;
}

void Usuario::setTelefono(const QString &newTelefono)
{
    telefono = newTelefono;
}

QString Usuario::getComidapreferida() const
{
    return comidapreferida;
}

void Usuario::setComidapreferida(const QString &newComidapreferida)
{
    comidapreferida = newComidapreferida;
}

QString Usuario::getDia() const
{
    return Dia;
}

void Usuario::setDia(const QString &newDia)
{
    Dia = newDia;
}

QString Usuario::getComidaDia() const
{
    return comidaDia;
}

void Usuario::setComidaDia(const QString &newComidaDia)
{
    comidaDia = newComidaDia;
}

Usuario::Usuario() {
    nombre="";
    correo="";
    telefono="";
    comidapreferida="";
    Dia="";
    comidaDia="";
}
