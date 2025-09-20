#include <iostream>
#include <fstream>
#include "tools.h"

using namespace std;

char* leerArchivo(const char* ruta_archivo){

    ifstream archivo(ruta_archivo);

    if(!archivo.is_open()){
        cerr << "Error al abrir el archivo";
        return nullptr;
    }

    long tamano = calcularTamanoArchivo(ruta_archivo);

    char* texto = new char[tamano + 1];

    if (!texto) {
        cerr << "Error de memoria." << endl;
        archivo.close();
        return nullptr;
    }

    archivo.read(texto, tamano);
    texto[tamano] = '\0';
    archivo.close();

    return texto;
}

long calcularTamanoArchivo(const char* ruta_archivo){
    long tamano;

    ifstream archivo(ruta_archivo);

    archivo.seekg(0, ios::end);
    tamano = archivo.tellg();
    archivo.seekg(0, ios::beg);

    archivo.close();

    return tamano;
}
