#include <iostream>
#include <fstream>
#include "tools.h"
#include <bitset>

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

void encriptar(const char* cadena_comprimida, int n, int K){

}

unsigned char* desencriptar(const char* cadena_encriptada, int tamano, int n, int K){
    unsigned char* cadena_desencriptada = new unsigned char[tamano];
    unsigned char b1, b2;

    for(int i=0; i != tamano; i++){
        char byte = cadena_encriptada[i];
        b1 = byte ^ K;
        b2 = rotarAlaDerecha(b1, n);
        cadena_desencriptada[i] = b2;
    }

    cadena_desencriptada[tamano] = '\0';

    return cadena_desencriptada;
}

unsigned char rotarAlaDerecha(unsigned char byte, int n) {
    return (byte >> n) | (byte << (8 - n));
}


unsigned char rotarAlaIzquierda(unsigned char byte, int n){
    return (byte << 2 | byte >> (8 - n));
}
