#include "storage.h"
#include <iostream>
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
