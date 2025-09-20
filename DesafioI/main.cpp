#include <iostream>
#include "tools.h"

using namespace std;


int main()
{

    const char* cadena_encriptada = leerArchivo(
        "/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/Encriptado1.txt");
    int tamano_cadena_encriptado = calcularTamanoArchivo(
        "/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/Encriptado1.txt");
    const char* cadena_pista = leerArchivo("/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/pista1.txt");

    cout << desencriptar(cadena_encriptada, tamano_cadena_encriptado, 3, 0x5A);

    return 0;
}

