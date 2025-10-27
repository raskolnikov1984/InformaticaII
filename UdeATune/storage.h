#ifndef STORAGE_H
#define STORAGE_H

#include <fstream>
#include <string>
#include "estructuras_datos/lista_dinamica.h"
#include "anuncio.h"
#include "cancion.h"
#include "favorito.h"

using namespace std;

class Storage
{
public:
  Storage();
  bool leerArchivo(string ruta_archivo, ifstream &archivo);
  void cargarCanciones(string &ruta_archivo, ListaDinamica<Cancion> &canciones);
  void cargarAnuncios(string &ruta_archivo, ListaDinamica<Anuncio> &anuncios);
  void cargarFavoritos(string &ruta_archivo,
                       ListaDinamica<Favorito> &favoritos);
  bool cargarFavoritosUsuario(const string& ruta_archivo, ListaDinamica<Favorito>& resultado, const string& usuario);
};

#endif // STORAGE_H
