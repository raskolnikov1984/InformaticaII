#ifndef ARTISTA_H_
#define ARTISTA_H_
#include <string>

using namespace std;

class Artista {

public:
  Artista();

    string getIdentificador() const;
    void setIdentificador(const string &newIdentificador);
    int getEdad() const;
    void setEdad(int newEdad);
    string getPais() const;
    void setPais(const string &newPais);
    int getSeguidores() const;
    void setSeguidores(int newSeguidores);
    int getPosicionTendencias() const;
    void setPosicionTendencias(int newPosicionTendencias);

private:
  string identificador;
  int edad;
  string pais;
  int seguidores;
  int posicionTendencias;
};

#endif // ARTISTA_H_
