#include "storage.h"
#include "estructuras_datos/lista_dinamica.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Storage::Storage() {}


bool Storage::leerArchivo(string ruta_archivo, ifstream& archivo) {
    archivo.open(ruta_archivo);

    if (!archivo.is_open()) {
      cerr << "Error al abrir el archivo" << endl;
      return false;
    }

    return true;
}


// En storage.cpp - versión corregida
void Storage::cargarCanciones(string &ruta_archivo, ListaDinamica<Cancion>& canciones) {
    ifstream canciones_file;
    string linea;
    string campo;
    stringstream ss;

    if (!leerArchivo(ruta_archivo, canciones_file)) {
        cerr << "No se pudo abrir el archivo: " << ruta_archivo << endl;
        return;
    }

    // Leer y descartar la cabecera
    getline(canciones_file, linea);
    while (getline(canciones_file, linea)) {
        stringstream ss(linea);
        Cancion nuevaCancion;

        // Leer identificador
        getline(ss, campo, ',');
        nuevaCancion.setIdentificador(campo);

        // Leer nombre
        getline(ss, campo, ',');
        nuevaCancion.setNombre(campo);

        // Leer album
        getline(ss, campo, ',');
        nuevaCancion.setAlbum(campo);

        // Leer duración
        getline(ss, campo, ',');
        nuevaCancion.setDuracion(campo);

        // Leer reproducciones
        getline(ss, campo, ',');
        try {
            int reproducciones = stoi(campo);
            nuevaCancion.setReproducciones(reproducciones);
        } catch (const exception& e) {
            cerr << "Error convirtiendo reproducciones: " << campo << endl;
            nuevaCancion.setReproducciones(0);
        }

        // Leer ubicación
        getline(ss, campo, ',');
        nuevaCancion.setUbicacionAudio(campo);

        canciones.agregar(nuevaCancion);
    }

    canciones_file.close();
}

void Storage::cargarAnuncios(string &ruta_archivo, ListaDinamica<Anuncio>& anuncios) {
  ifstream anuncios_file;
  string linea;
  string campo;
  char categoria;
  stringstream ss;

  if (!leerArchivo(ruta_archivo, anuncios_file)) {
    cerr << "No se pudo abrir el archivo: " << ruta_archivo << endl;
    return;
  }

  // Leer y descartar la cabecera
  getline(anuncios_file, linea);
  while (getline(anuncios_file, linea)) {
    stringstream ss(linea);
    Anuncio nuevoAnuncio;

    // Leer identificador
    getline(ss, campo, ',');
    nuevoAnuncio.setMensaje(campo);

    // Leer nombre
    getline(ss, campo, ',');
    categoria = campo[0];
    nuevoAnuncio.setCategoria(categoria);

    // Leer reproducciones
    getline(ss, campo, ',');
    try {
      int prioridad = stoi(campo);
      nuevoAnuncio.setPrioridad(prioridad);
    } catch (const exception& e) {
      cerr << "Error convirtiendo reproducciones: " << campo << endl;
      nuevoAnuncio.setPrioridad(0);
    }

    anuncios.agregar(nuevoAnuncio);
  }

  anuncios_file.close();
}

void Storage::cargarFavoritos(string &ruta_archivo,
                              ListaDinamica<Favorito> &favoritos) {
  ifstream favoritos_file;
  string linea;
  string campo;
  stringstream ss;

  if (!leerArchivo(ruta_archivo, favoritos_file)) {
    cerr << "No se pudo abrir el archivo: " << ruta_archivo << endl;
    return;
  }

  // Leer y descartar la cabecera
  getline(favoritos_file, linea);
  while (getline(favoritos_file, linea)) {
    stringstream ss(linea);
    getline(ss, campo, ',');

    Favorito nuevoFavorito;
    nuevoFavorito.setUsuario(campo);

    getline(ss, campo, ',');
    nuevoFavorito.setCancionId(campo);
    favoritos.agregar(nuevoFavorito);
  }
  favoritos_file.close();
}

bool Storage::cargarFavoritosUsuario(const string& ruta_archivo,
                                   ListaDinamica<Favorito>& resultado,
                                   const string& usuario) {
    ifstream archivo(ruta_archivo);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir " << ruta_archivo << endl;
        return false;
    }

    string linea;
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        size_t pos = 0;
        string token;

        pos = linea.find(',');
        if (pos == string::npos) continue;

        string usuarioArchivo = linea.substr(0, pos);
        string cancionId = linea.substr(pos + 1);

        if (usuarioArchivo == usuario) {
            Favorito fav(usuarioArchivo, cancionId);
            resultado.agregar(fav);
        }
    }

    archivo.close();
    return true;
}
