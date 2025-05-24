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
    string password;

public:
    Usuario(); // constructor por defecto
    Usuario(const string& tipoUsuario, const string& numeroDocumento, int antiguedad, float puntuacion);
    string tabla = "usuarios.txt";
    string getNumeroDocumento() const;

    //getters
    int getAntiguedad() const;
    float getPuntuacion() const;
    string getTipoUsuario() const;

    //setters
    void setTipoUsuario(const string &newTipoUsuario);
    void setNumeroDocumento(const string &newNumeroDocumento);
    void setAntiguedad(int newAntiguedad);
    void setPuntuacion(float newPuntuacion);
    void setPassword(const string &newPassword);
};

#endif // USUARIO_H
