#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "./estructuras_datos/lista_dinamica.h"
#include "cancion.h"

using namespace std;

class Album {
public:
    string getIdentificador() const;
    void setIdentificador(const string &newIdentificador);
    string getArtista() const;
    void setArtista(const string &newArtista);
    string getGenero() const;
    void setGenero(const string &newGenero);
    string getFechaLanzamiento() const;
    void setFechaLanzamiento(const string &newFechaLanzamiento);
    string getDuracion() const;
    void setDuracion(const string &newDuracion);
    string getNombre() const;
    void setNombre(const string &newNombre);
    string getSello() const;
    void setSello(const string &newSello);
    string getPuntuacion() const;
    void setPuntuacion(const string &newPuntuacion);

  ListaDinamica<Cancion> canciones;

    string getUbicacionImagen() const;
    void setUbicacionImagen(const string &newUbicacionImagen);

private:
  string identificador;
  string artista;
  string genero;
  string fechaLanzamiento;
  string duracion;
  string nombre;
  string sello;
  string puntuacion;
  string ubicacionImagen;
};
#endif // USUARIO_H
