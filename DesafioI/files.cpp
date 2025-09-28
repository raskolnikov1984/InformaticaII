#include <iostream>
#include <fstream>
#include "files.h"

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

void limpiarCadena(char*& cadena_limpia, char* archivo_desencriptado, int& tamano_cadena_descomprimida, int& tamano_cadena_limpia, int tamano){
    int posicion = 0;
    for(int i=0; i < tamano; i++){
        if((static_cast<int>(archivo_desencriptado[i]) >= 1) || isalnum(archivo_desencriptado[i])){
            if(archivo_desencriptado[i] >= 1 && !isprint(archivo_desencriptado[i])){
                tamano_cadena_descomprimida += archivo_desencriptado[i];
                cadena_limpia[posicion] = archivo_desencriptado[i] + 48;
                tamano_cadena_limpia+=1;
                posicion++;

                continue;
            }

            cadena_limpia[posicion] = archivo_desencriptado[i];
            tamano_cadena_limpia += 1;
            posicion++;
        }
    }
    cadena_limpia[tamano_cadena_limpia] = '\0';
}
