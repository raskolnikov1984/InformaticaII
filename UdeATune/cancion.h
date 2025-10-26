#ifndef CANCION_H_
#define CANCION_H_

#include <iostream>
#include <string>

using namespace std;

class Cancion {
public:
  Cancion();
  string getIdentificador() const;
  void setIdentificador(const string &newIdentificador);
  string getNombre() const;
  void setNombre(const string &newNombre);
  string getAlbum() const;
  void setAlbum(const string &newAlbum);
  string getDuracion() const;
  void setDuracion(const string &newDuracion);
  string getUbicacionAudio() const;
  void setUbicacionAudio(const string &newUbicacion);
  string getCreditos() const;
  void setCreditos(const string &newCreditos);
  int getReproducciones() const;
  void setReproducciones(int newReproducciones);

  void imprimirInformacion();

private:
  string identificador;
  string nombre;
  string album;
  string duracion;
  string ubicacionAudio;
  string creditos;
  int reproducciones;
};

#endif // CANCION_H_
