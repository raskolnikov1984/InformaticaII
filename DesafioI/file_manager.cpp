#include <fstream>
#include <iostream>
#include "file_manager.h"

using namespace std;

int escribirArchivo(char* nombreArchivo, unsigned char* contenido){
    fstream archivo(nombreArchivo, ios::in | ios::out | ios::app);

    if(!archivo){
        cerr << "Error al abrir el archivo en modo lectura" << endl;

        return 1;
    }

    archivo << contenido;
    archivo.close();

    return 0;
}
