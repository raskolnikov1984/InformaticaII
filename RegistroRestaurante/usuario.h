#ifndef USUARIO_H
#define USUARIO_H
#include <QString>

class Usuario
{

private:
    QString nombre;
    QString correo;
    QString telefono;
    QString comidapreferida;
    QString Dia;
    QString comidaDia;

public:
    Usuario();
    ~Usuario();

    QString getNombre() const;
    void setNombre(const QString &newNombre);
    QString getCorreo() const;
    void setCorreo(const QString &newCorreo);
    QString getTelefono() const;
    void setTelefono(const QString &newTelefono);
    QString getComidapreferida() const;
    void setComidapreferida(const QString &newComidapreferida);
    QString getDia() const;
    void setDia(const QString &newDia);
    QString getComidaDia() const;
    void setComidaDia(const QString &newComidaDia);
};

#endif // USUARIO_H
