#include <iostream>
#include "tools.h"

using namespace std;

unsigned char rotarAlaDerecha(unsigned char byte, int n) {
    return (byte >> n) | (byte << (8 - n));
}

char* desencriptar(const char* archivo_encriptado, int tamano, int n, int K){
    char* cadena_desencriptada = new char[tamano];
    char b1, b2;

    for(int i=0; i != tamano; i++){
        char byte = archivo_encriptado[i];
        b1 = byte ^ K;
        b2 = rotarAlaDerecha(b1, n);

        cout << b2;
        cadena_desencriptada[i] = static_cast<int>(b2);
    }

    cadena_desencriptada[tamano] = '\0';

    return cadena_desencriptada;
}


int main()
{

    const char* archivo_encriptado = leerArchivo(
        "/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/Encriptado1.txt");
    int tamano_archivo_encriptado = calcularTamanoArchivo(
        "/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/Encriptado1.txt");
    const char* archivo_pista = leerArchivo("/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/pista1.txt");

    cout << desencriptar(archivo_encriptado, tamano_archivo_encriptado, 3, 0x5A)[0];

    return 0;
}

