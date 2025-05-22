#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class Usuario {
private:
    int id;
    string tipoUsuario;
    string numeroDocumento;
    int antiguedad;
    float puntuacion;

public:
    Usuario(const string& tipoUsuario, const string& numeroDocumento, int antiguedad, float puntuacion);
    string tabla = "usuarios.txt";
    string getNumeroDocumento() const;
    int getAntiguedad() const;
    float getPuntuacion() const;
    string getTipoUsuario() const;
};

#endif // USUARIO_H
