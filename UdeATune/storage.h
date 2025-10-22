#ifndef STORAGE_H
#define STORAGE_H

#include <fstream>
#include <string>
#include "estructuras_datos/lista_dinamica.h"
#include "cancion.h"

using namespace std;

class Storage
{
public:
  Storage();
  bool leerArchivo(string ruta_archivo, ifstream &archivo);
  void cargarCanciones(string& ruta_archivo, ListaDinamica<Cancion>& canciones);
};

#endif // STORAGE_H
