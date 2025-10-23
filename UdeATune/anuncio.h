#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include <string>

using namespace std;

class Anuncio {
public:
    Anuncio();
    Anuncio(const string &mensaje, char categoria, int priorida);
    string getMensaje() const;
    void setMensaje(const string &newMensaje);
    char getCategoria() const;
    void setCategoria(char newCategoria);
    int getPrioridad() const;
    void setPrioridad(int newPriorida);

private:
  string mensaje;
  char categoria;
  int prioridad;
};

#endif // ANUNCIO_H_
