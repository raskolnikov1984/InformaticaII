#ifndef STORAGE_H
#define STORAGE_H

#include <fstream>
#include <string>

using namespace std;

class Storage
{
public:
  Storage();
  bool leerArchivo(string ruta_archivo, ifstream& archivo);
};

#endif // STORAGE_H
