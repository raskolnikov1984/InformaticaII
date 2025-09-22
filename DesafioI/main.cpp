#include <iostream>
//#include "tools.h"
#include "rle.h"

using namespace std;

bool es_subcadena(const char* cadena1, const char* cadena2) {
    // Verificar si alguna de las cadenas es nula
    if (cadena1 == nullptr || cadena2 == nullptr) {
        return false; // No se puede verificar
    }

    // Obtener la longitud de las cadenas
    const char* p1 = cadena1;
    const char* p2 = cadena2;

    // Recorrer la primera cadena
    while (*p1 != '\0') {
        const char* inicio = p2; // Guardar el inicio de cadena2
        const char* p = p1;

        // Comparar caracteres de cadena1 con cadena2
        while (*p != '\0' && *inicio != '\0' && *p == *inicio) {
            p++;
            inicio++;
        }

        // Si hemos llegado al final de cadena1, es subcadena
        if (*p == '\0') {
            return true;
        }

        p1++; // Moverse al siguiente carácter de cadena1
    }

    // Repetir el proceso para verificar si cadena2 es subcadena de cadena1
    p1 = cadena2;
    p2 = cadena1;

    while (*p1 != '\0') {
        const char* inicio = p2; // Guardar el inicio de cadena1
        const char* p = p1;

        // Comparar caracteres de cadena2 con cadena1
        while (*p != '\0' && *inicio != '\0' && *p == *inicio) {
            p++;
            inicio++;
        }

        // Si hemos llegado al final de cadena2, es subcadena
        if (*p == '\0') {
            return true;
        }

        p1++; // Moverse al siguiente carácter de cadena2
    }

    return false; // Ninguna es subcadena de la otra
}

int main()
{

    //const char* cadena_encriptada = leerArchivo(
    //    "/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/Encriptado1.txt");
    //int tamano_cadena_encriptado = calcularTamanoArchivo(
    //    "/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/Encriptado1.txt");
    //const char* cadena_pista = leerArchivo("/home/rodia/Desktop/04-UdeA/InformaticaII/DesafioI/dataset/pista2.txt");

    /*Encriptado1*/
    //unsigned char *cadena_desencriptada = desencriptar(cadena_encriptada, tamano_cadena_encriptado, 3, 0x5A);

    /*Encriptado2*/
    // Sunsigned char* cadena_desencriptada = desencriptar(cadena_encriptada, tamano_cadena_encriptado, 3, 0x5A);

    char cadenaAComprimir[] = "AAAABBBCCDAA";
    cadenaComprimidaRLEstruct* segmentos = comprimirRLE(cadenaAComprimir);

    char cadenaADescomprimir[] = "4A3B2C1D2A";

    cout << descomprimirCadenaRLE(segmentos);

    return 0;
}

